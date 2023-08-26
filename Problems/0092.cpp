class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode top;
        top.next = head;
        ListNode *prev = &top;

        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode *crnt = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode *tmp = prev->next;
            prev->next = crnt->next;
            crnt->next = crnt->next->next;
            prev->next->next = tmp;
        }

        return top.next;
    }
};
