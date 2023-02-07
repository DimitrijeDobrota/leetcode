class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *mid = getMid(head), *left = sortList(head),
             *right = sortList(mid);
    return merge(left, right);
  }

  ListNode *merge(ListNode *list1, ListNode *list2) {
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

  ListNode *getMid(ListNode *head) {
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    fast = slow->next;
    slow->next = nullptr;
    return fast;
  }
};
