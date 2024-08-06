class Solution {
  public:
    int maxSumDivThree(const vector<int> &nums) const {
        vector<int> dp(3, 0);

        for (const int n : nums) {
            for (const int m : vector<int>(dp)) {
                dp[(m + n) % 3] = max(dp[(m + n) % 3], m + n);
            }
        }

        return dp[0];
    }
};
