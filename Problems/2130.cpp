class Solution {
    ListNode *pre_mid(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *p = head, *q = nullptr, *r = nullptr;
        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }

  public:
    int pairSum(ListNode *head) {
        ListNode *pre = pre_mid(head);
        ListNode *head2 = reverse(pre->next);

        int maxi = INT_MIN;
        for (ListNode *p = head, *q = head2; q; p = p->next, q = q->next)
            maxi = max(p->val + q->val, maxi);

        pre->next = reverse(head2);
        return maxi;
    }
};
