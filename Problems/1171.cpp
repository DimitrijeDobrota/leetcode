class Solution {
  public:
    ListNode *removeZeroSumSublists(ListNode *head) const {
        unordered_map<int, ListNode *> um;
        ListNode dummy(0, head);
        int crnt = 0;

        for (ListNode *c = &dummy; c; c = c->next) {
            crnt += c->val;
            if (um.count(crnt)) {
                ListNode *p = um[crnt];
                c = p->next;

                int v = crnt + c->val;
                while (v != crnt) {
                    um.erase(v);
                    c = c->next;
                    v += c->val;
                }

                p->next = c->next;
            } else
                um[crnt] = c;
        }

        return dummy.next;
    }
};
