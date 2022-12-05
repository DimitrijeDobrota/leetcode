class Solution {
public:
  ListNode *invert(ListNode *head) {
    ListNode *p, *q, *r;

    p = head;
    q = nullptr;
    while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    return q;
  }

  ListNode *first_half_end(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  bool isPalindrome(ListNode *head) {
    if (!head || !head->next) return true;

    ListNode *fhe = first_half_end(head);
    ListNode *shs = invert(fhe->next);

    for (ListNode *p = head, *tmp = shs; tmp; p = p->next, tmp = tmp->next)
      if (p->val != tmp->val) return false;

    return true;
  }
};
