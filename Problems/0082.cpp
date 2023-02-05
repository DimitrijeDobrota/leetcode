class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode top(-200, head);

    for (ListNode *p = &top, *c = head; c && c->next; c = c->next) {
      if (c->val == c->next->val) {
        while (c && c->next && c->val == c->next->val) c = c->next;
        p->next = c->next;
        if (!c) break;
      } else
        p = p->next;
    }

    return top.next;
  }
};
