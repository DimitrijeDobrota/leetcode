class Solution {
  public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        ListNode *prev = head, *crnt = head->next;

        for (int lvl = 2; crnt; lvl++) {
            ListNode *bg = prev;

            int size = 0;
            while (crnt && size < lvl) {
                prev = crnt;
                crnt = crnt->next;
                size++;
            }

            if (size % 2) continue;

            crnt = bg->next;
            ListNode *last = crnt, *first = crnt, *tmp;
            while (size--) {
                tmp = crnt;
                crnt = crnt->next;
                tmp->next = last;
                last = tmp;
            }
            bg->next = last;
            first->next = crnt;
            prev = first;
        }

        return head;
    }
};
