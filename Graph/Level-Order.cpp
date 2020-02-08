/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode*> Q;
    Q.push(A);
    vector<vector<int>> ans;
    while(!Q.empty()){
        int levelSize = Q.size();
        vector<int> level;
        while(--levelSize){
            TreeNode* temp = Q.front();
            level.push_back(temp->val);
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
            Q.pop();
        }
        ans.push_back(level);
    }
    return ans;
}
