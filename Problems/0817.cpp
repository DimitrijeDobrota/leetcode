class Solution {
  public:
    int numComponents(ListNode *head, vector<int> &nums) {
        static int seen[10001];
        memset(seen, 0x00, sizeof(seen));
        for (const int n : nums)
            seen[n] = true;

        int res = 0, started = 0;
        for (const ListNode *crnt = head; crnt; crnt = crnt->next) {
            if (!seen[crnt->val])
                res += started, started = 0;
            else
                started = 1;
        }
        res += started;
        return res;
    }
};
