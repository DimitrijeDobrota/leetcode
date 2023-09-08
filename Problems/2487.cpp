class Solution {
    ListNode *rev(ListNode *list) {
        ListNode *prev = nullptr, *next;
        while (list) {
            next = list->next;
            list->next = prev;
            prev = list;
            list = next;
        }
        return prev;
    }

  public:
    ListNode *removeNodes(ListNode *head) {
        ListNode dummy(-1, rev(head));
        int maxi = -1;
        for (ListNode *crnt = &dummy; crnt && crnt->next; crnt = crnt->next) {
            maxi = max(maxi, crnt->val);
            while (crnt->next && crnt->next->val < maxi)
                crnt->next = crnt->next->next;
        }
        return rev(dummy.next);
    }
};
