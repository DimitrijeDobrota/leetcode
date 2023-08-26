class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2) {
        ListNode *head, *t;
        t = head = new ListNode();

        int add = 0;
        while (list1 || list2 || add) {
            if (list1) {
                add += list1->val;
                list1 = list1->next;
            }
            if (list2) {
                add += list2->val;
                list2 = list2->next;
            }
            t = t->next = new ListNode(add % 10);
            add /= 10;
        }

        return head->next;
    }
};
