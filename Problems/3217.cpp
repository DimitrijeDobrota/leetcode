class Solution {
  public:
    ListNode *modifiedList(const vector<int> &nums, ListNode *head) const {
        const unordered_set<int> us(begin(nums), end(nums));
        ListNode dummy(-1, head);

        for (auto *p = &dummy; p && p->next;) {
            if (!us.count(p->next->val))
                p = p->next;
            else
                p->next = p->next->next;
        }

        return dummy.next;
    }
};
