class Solution {
  public:
    int maxSumDivThree(const vector<int> &nums) const {
        int dp[3] = {0}, prev[3];

        for (const int n : nums) {
            memcpy(prev, dp, 3 * sizeof(int));
            for (const int prev : span(prev, 3)) {
                dp[(prev + n) % 3] = max(dp[(prev + n) % 3], prev + n);
            }
        }

        return dp[0];
    }
};
