class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head) return nullptr;

    ListNode *h, *t, *p;
    t = h = new ListNode();

    for (p = head; p && p->next;) {
      t = t->next = p->next;
      p->next = p->next->next;
      if (p->next) p = p->next;
    }
    p->next = h->next;
    t->next = nullptr;
    return head;
  }
};
