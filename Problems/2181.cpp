class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    if (!head) return nullptr;
    for (ListNode *p = head; p->next->next;)
      if (p->val == 0 && p->next->val != 0 && p->next->next->val != 0) {
        p->next->next->val += p->next->val;
        p->next = p->next->next;
      } else
        p = p->next;

    for (ListNode *p = head; p->next;)
      if (!p->next->val)
        p->next = p->next->next;
      else
        p = p->next;

    return head->val ? head : head->next;
  }
};
