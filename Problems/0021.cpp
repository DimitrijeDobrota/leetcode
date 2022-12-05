class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head, *t;
    t = head = new ListNode();

    while (list1 && list2) {
      if (list1->val < list2->val) {
        t = t->next = list1;
        list1 = list1->next;
      } else {
        t = t->next = list2;
        list2 = list2->next;
      }
    }

    while (list1) {
      t = t->next = list1;
      list1 = list1->next;
    }

    while (list2) {
      t = t->next = list2;
      list2 = list2->next;
    }

    return head->next;
  }
};
