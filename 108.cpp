/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& A) {
        if(A.size() == 0) return NULL;
        if(A.size() == 1) return (new TreeNode(A[0]));
        int mid = A.size()/2;
        TreeNode* root = new TreeNode(A[mid]);
        vector<int> leftChild(A.begin(), A.begin() + mid);
        vector<int> rightChild(A.begin() + mid + 1, A.end());
        root->left = sortedArrayToBST(leftChild);
        root->right = sortedArrayToBST(rightChild);
        return root;
    }
};
