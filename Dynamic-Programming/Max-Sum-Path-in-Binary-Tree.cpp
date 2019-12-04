/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxGain(TreeNode* root, int &maxSum){
    if(root == NULL) return 0;
    int leftGain = max(0, maxGain(root->left, maxSum));
    int rightGain = max(0, maxGain(root->right, maxSum));
    int pathPrice = leftGain + rightGain + root->val;
    maxSum = max(maxSum, pathPrice);
    return root->val + max(leftGain, rightGain);
}
int Solution::maxPathSum(TreeNode* A) {
    int maxSum = INT_MIN;
    maxGain(A, maxSum);
    return maxSum;
}
