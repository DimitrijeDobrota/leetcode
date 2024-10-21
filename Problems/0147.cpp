class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) const {
        ListNode dummy(-1, head);
        ListNode *prev = &dummy, *crnt = head;

        for (; crnt; prev = crnt, crnt = crnt->next) {
            if (prev->val <= crnt->val) continue;
            for (ListNode *p = &dummy, *c = dummy.next; p != prev; p = c, c = c->next) {
                if (c->val <= crnt->val) continue;
                prev->next = crnt->next;
                crnt->next = p->next;
                p->next = crnt;
                crnt = prev;
                break;
            }
        }

        return dummy.next;
    }
};
