class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return nullptr;

        for (ListNode *p = head; p && p->next;)
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;

        if (head->val == val) head = head->next;

        return head;
    }
};
