class Solution {
    ListNode *pre_mid(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

  public:
    ListNode *deleteMiddle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *pre = pre_mid(head);
        pre->next = pre->next->next;
        return head;
    }
};
