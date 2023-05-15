class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *tmp = head, *first;
    while (--k) tmp = tmp->next;
    first = tmp;

    ListNode *second = head;
    tmp = tmp->next;
    while (tmp) tmp = tmp->next, second = second->next;
    swap(first->val, second->val);
    return head;
  }
};
