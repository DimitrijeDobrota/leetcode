class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *d = new ListNode(-1, head);
        for (ListNode *p = d; p->next && p->next->next;) {
            ListNode *t = p->next;
            p->next = p->next->next;
            t->next = p->next->next;
            p->next->next = t;
            p = t;
        }
        return d->next;
    }
};
