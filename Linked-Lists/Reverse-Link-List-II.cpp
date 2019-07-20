ListNode* reverse(ListNode* head)
{
    ListNode* current = head;
    ListNode* prev = NULL;
    while(current)
    {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B == C) return A;
    ListNode *start = NULL, *startPrev = NULL, *end = NULL, *endNext = NULL;
    ListNode *temp = A;
    int i = 1;
    while(temp && i <= C)
    {
        if(i < B)
            startPrev = temp;
        if(i == B)
            start = temp;
        if(i == C)
        {
            end = temp;
            endNext = temp->next;
        }
        temp = temp->next;
        i++;
    }
    end->next = NULL;
    end = reverse(start);
    if(startPrev) startPrev->next = end;
    else A = end;
    start->next = endNext;
    return A;
}
