

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */
    ListNode* reverse(ListNode* A)
    {
        ListNode *prev = NULL, *curr = A;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
     
    ListNode* Solution::reorderList(ListNode* A) {
        ListNode *slow = A, *fast = A->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* B = slow->next;
        slow->next = NULL;
        ListNode* C = reverse(B);
        ListNode* temp = new ListNode(0);
        B = temp;
        while(A || C)
        {
            if(A)
            {
                temp->next = A;
                temp = temp->next;
                A = A->next;
            }
            if(C)
            {
                temp->next = C;
                temp = temp->next;
                C = C->next;
            }
        }
        return B->next;
    }

