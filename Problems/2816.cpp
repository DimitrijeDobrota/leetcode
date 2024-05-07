class Solution {
    static ListNode *rev(ListNode *list) {
        ListNode *prev = nullptr, *next;
        while (list) {
            next = list->next;
            list->next = prev;
            prev = list;
            list = next;
        }
        return prev;
    }

  public:
    ListNode *doubleIt(ListNode *head) const {
        head = rev(head);

        ListNode *l = nullptr;
        int carry = 0;
        for (ListNode *p = head; p; l = p, p = p->next) {
            const int val = p->val * 2 + carry;
            p->val = val % 10;
            carry = val / 10;
        }

        if (carry) l->next = new ListNode(carry);

        return rev(head);
    }
};
