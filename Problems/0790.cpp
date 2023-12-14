class Solution {
  public:
    int numTilings(int n) const {
        static const int MOD = 1E9 + 7;
        static long long dp[1001] = {0, 1, 2, 5};
        memset(dp + 4, 0x00, sizeof(dp) - 16);
        if (n <= 3) return dp[n];
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};
