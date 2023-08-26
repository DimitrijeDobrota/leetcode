class Solution {
  public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1);
        double sum = 1.0, ans = 0.0;

        dp[0] = 1.0;
        for (int i = 1; i < n + 1; i++) {
            dp[i] = sum / maxPts;
            (i < k ? sum : ans) += dp[i];
            if (i - maxPts >= 0) sum -= dp[i - maxPts];
        }

        return ans;
    }
};
