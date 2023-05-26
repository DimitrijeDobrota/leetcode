class Solution {
  int dp[10001][101];

public:
  Solution() { memset(dp, 0, sizeof(dp)); }

  int stoneGameII(const vector<int> &piles) {
    int n = piles.size();
    vector<int> sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      dp[i][n] = sum[i] = sum[i + 1] + piles[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 1; j--) {
        for (int X = 1; X <= 2 * j && i + X <= n; X++) {
          dp[i][j] = max(dp[i][j], sum[i] - dp[i + X][max(j, X)]);
        }
      }
    }
    return dp[0][1];
  }
};
