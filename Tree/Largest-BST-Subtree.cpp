/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct data{
  int size, lower, upper, ans;
  bool isBST;
};

data largestBST(TreeNode* A){
    if(A == NULL) return {0, INT_MAX, INT_MIN, 0, true};
    if(A->left == NULL && A->right == NULL) return {1, A->val, A->val, 1, true};
    data left = largestBST(A->left);
    data right = largestBST(A->right);
    data curr;
    curr.size = left.size + right.size + 1;
    if(left.isBST && right.isBST && left.upper < A->val && right.lower > A->val){
        curr.lower = min(left.lower, min(right.lower, A->val));
        curr.upper = max(right.upper, max(left.upper, A->val));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}
int Solution::solve(TreeNode* A) {
    data foo = largestBST(A);
    return foo.ans;
}

