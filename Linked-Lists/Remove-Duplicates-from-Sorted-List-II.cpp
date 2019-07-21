/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *fakeHead = new ListNode;
    fakeHead->next = A;
    ListNode* prev = fakeHead, *curr = A;
    while(curr)
    {
        while(curr->next && curr->val == curr->next->val)
            curr = curr->next;
            
        curr = curr->next;
    }
    return fakeHead->next;
}
