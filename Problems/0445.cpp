class Solution {
  public:
    pair<ListNode *, int> reverse(ListNode *root) {
        ListNode *l = nullptr, *c = root;
        int size = 0;
        while (c) {
            ListNode *n = c->next;
            c->next = l;
            l = c;
            c = n;
            size++;
        }
        return {l, size};
    }

    ListNode *addTwoNumbers(ListNode *p1, ListNode *p2) {
        auto [l1, s1] = reverse(p1);
        auto [l2, s2] = reverse(p2);

        if (s2 > s1) swap(l1, l2);
        p1 = l1;

        int carry = 0;
        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
        }

        if (l1) {
            while (true) {
                int sum = l1->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
                if (!l1->next) break;
                l1 = l1->next;
            }
        }

        if (!carry) return reverse(p1).first;
        return new ListNode(carry, reverse(p1).first);
    }
};
