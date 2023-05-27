class Solution {
public:
  string stoneGameIII(const vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> sum(n + 1, 0), dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) sum[i] = sum[i + 1] + stoneValue[i];

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = stoneValue[i] + sum[i + 1] - dp[i + 1];
      for (int k = i + 1; k < i + 3 && k < n; k++) {
        dp[i] = max(dp[i], sum[i] - dp[k + 1]);
      }
    }
    dp[0] = dp[0] * 2 - sum[0];
    return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
  }
};
