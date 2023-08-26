class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        ListNode hless, hmore;
        ListNode *less = &hless, *more = &hmore;

        for (ListNode *crnt = head; crnt; crnt = crnt->next) {
            if (crnt->val < x)
                less = less->next = crnt;
            else
                more = more->next = crnt;
        }

        less->next = hmore.next;
        more->next = nullptr;
        return hless.next;
    }
};
