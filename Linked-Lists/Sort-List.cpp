/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode *A, ListNode *B)
{
    ListNode *temp = new ListNode(0), *foo = temp;
    while(A && B)
    {
        if(A->val < B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else
        {
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    if(A) temp->next = A;
    if(B) temp->next = B;
    return foo->next;
}
 
ListNode* Solution::sortList(ListNode* A) {
    if(A == NULL || A->next == NULL) return A;
    
    /* 1. Dividing list into two halves */
    ListNode *slow = A, *fast = A->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* B = slow->next;
    slow->next = NULL;
    
    /* 2. Recursively dividing two parts */
    /* 3. Merge both lists*/
    return merge(sortList(A), sortList(B));
}
