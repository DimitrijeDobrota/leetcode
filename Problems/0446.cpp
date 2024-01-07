class Solution {
  public:
    int numberOfArithmeticSlices(const vector<int> &nums) const {
        vector<unordered_map<long long, int>> dp(size(nums));
        int res = 0;
        for (int i = 1; i < size(nums); i++) {
            for (int j = 0; j < i; j++) {
                const long long diff = (long long)nums[i] - nums[j];
                const int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                res += cnt;
            }
        }
        return res;
    }
};
