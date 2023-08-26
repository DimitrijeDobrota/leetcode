class Solution {
  public:
    int tallestBillboard(const vector<int> &rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;

        for (int rod : rods) {
            vector<int> dpc = dp;
            for (int i = 0; i <= sum - rod; i++) {
                if (dpc[i] < 0) continue;
                dp[i + rod] = max(dp[i + rod], dpc[i]);
                dp[abs(i - rod)] = max(dp[abs(i - rod)], dpc[i] + min(i, rod));
            }
        }
        return dp[0];
    }
};
