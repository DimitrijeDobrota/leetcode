class Solution {
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *prev = head, *crnt = head->next, *next;
        vector<int> res(2, INT_MAX);
        int first = 0, last = 0;
        for (int pos = 1; next = crnt->next; pos++) {
            if (crnt->val > prev->val && crnt->val > next->val ||
                crnt->val < prev->val && crnt->val < next->val) {
                if (!first)
                    first = last = pos;
                else {
                    res[0] = min(res[0], pos - last);
                    res[1] = pos - first;
                    last = pos;
                }
            }
            prev = crnt;
            crnt = next;
        }
        if (res[0] == INT_MAX) res[0] = -1;
        if (res[1] == INT_MAX) res[1] = -1;
        return res;
    }
};
