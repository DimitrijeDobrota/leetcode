class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *p, *q, *r;

    p = head, q = nullptr;
    while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }

    return q;
  }
};
