class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode head, *t = &head;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        t = t->next = list1;
        list1 = list1->next;
      } else {
        t = t->next = list2;
        list2 = list2->next;
      }
    }

    t->next = list1 ? list1 : list2;
    return head.next;
  }
};
