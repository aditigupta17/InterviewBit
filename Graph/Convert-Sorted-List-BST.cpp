/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* foo(ListNode* &A, int start, int end)
{
    if(start>end) return NULL;
    int mid = (start+end)/2;
    TreeNode *leftSub = foo(A, start, mid-1);
    TreeNode *root = new TreeNode(A->val);
    A = A->next;
    TreeNode *rightSub = foo(A, mid+1, end);
    root->left = leftSub;
    root->right = rightSub;
    return root;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A == NULL) return NULL;
    int len = 0;
    ListNode *temp = A;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return foo(A, 0, len-1);
}
