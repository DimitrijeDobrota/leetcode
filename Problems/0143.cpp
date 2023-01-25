class Solution {
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

  ListNode *bmiddleNode(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

public:
  void reorderList(ListNode *head) {
    ListNode *bmid = bmiddleNode(head);
    ListNode *rev = reverseList(bmid->next);
    bmid->next = nullptr;

    ListNode top, *tmp = &top, *a, *b, *an;
    for (a = head, b = rev; b; b = b->next, a = an) {
      an = a->next;
      tmp = tmp->next = a;
      tmp = tmp->next = b;
    }
    if (a) tmp = tmp->next = a;
    tmp->next = nullptr;
  }
};
