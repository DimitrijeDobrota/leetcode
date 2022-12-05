class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return nullptr;
    for (ListNode *p = head; p->next;)
      if (p->val == p->next->val)
        p->next = p->next->next;
      else
        p = p->next;
    return head;
  }
};
