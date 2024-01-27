class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int kInversePairs(int n, int k) {
        static int dp[1001][1001];
        memset(dp, 0x00, sizeof(dp));

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0)) % MOD;
                if (j >= i) dp[i][j] = (MOD + dp[i][j] - dp[i - 1][j - i]) % MOD;
            }
        }
        return dp[n][k];
    }
};

// Space optimized
class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int kInversePairs(int n, int k) {
        static int dp[2][1001];
        memset(dp, 0x00, sizeof(dp));

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i % 2][j] = (dp[(i - 1) % 2][j] + (j > 0 ? dp[i % 2][j - 1] : 0)) % MOD;
                if (j >= i) dp[i % 2][j] = (MOD + dp[i % 2][j] - dp[(i - 1) % 2][j - i]) % MOD;
            }
        }
        return dp[n % 2][k];
    }
};
