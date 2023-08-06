class Solution {
  static const int MOD = 1e9 + 7;
  long dp[101][101] = {1, 0};

public:
  int numMusicPlaylists(int n, int goal, int k) {
    for (int i = 1; i <= goal; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
        if (j > k) {
          dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - k)) % MOD) % MOD;
        }
      }
    }
    return (int)dp[goal][n];
  }
};
