class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *b = head;

        n++;
        for (ListNode *a = head; a; a = a->next) {
            if (!n)
                b = b->next;
            else
                n--;
        }
        if (n)
            head = head->next;
        else
            b->next = b->next->next;
        return head;
    }
};
