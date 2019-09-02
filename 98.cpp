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
    bool check(TreeNode* temp, long left, long right)
    {
        if(temp == NULL) return true;
        if(!(temp->val > left && temp->val < right)) return false;
        return check(temp->left, left, temp->val) && check(temp->right, temp->val, right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return check(root->left, (long)INT_MIN - 1, root->val) && check(root->right, root->val, (long)INT_MAX + 1);
    }
};
