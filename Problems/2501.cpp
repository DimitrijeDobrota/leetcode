class Solution {
  public:
    int longestSquareStreak(vector<int> &nums) {
        static int seen[100001];

        memset(seen, 0x00, sizeof(seen));
        sort(begin(nums), end(nums));

        int res = 0;
        for (int i = 0; i < size(nums); i++) {
            const int crnt = nums[i];
            if (crnt < 317) {
                seen[crnt * crnt] = seen[crnt] + 1;
            }
            res = max(res, seen[crnt]);
        }

        return res ? res + 1 : -1;
    }
};
