class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode *res = nullptr;

    for (ListNode *p = headA; p; p = p->next) p->val = -p->val;

    for (ListNode *p = headB; p; p = p->next)
      if (p->val < 0) {
        res = p;
        break;
      }

    for (ListNode *p = headA; p; p = p->next) p->val = -p->val;

    return res;
  }
};
