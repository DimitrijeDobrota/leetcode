class Solution {
    static const int MOD = 1e9 + 7;
    static int dp[2][3][100001];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int checkRecord(int n, int a = 0, int l = 0) const {
        if (n == 0) return 1;
        if (dp[a][l][n] != -1) return dp[a][l][n];

        int res = checkRecord(n - 1, a, 0);
        if (l < 2) res = (res + checkRecord(n - 1, a, l + 1)) % MOD;
        if (a < 1) res = (res + checkRecord(n - 1, a + 1, 0)) % MOD;

        return dp[a][l][n] = res;
    }
};

int Solution::dp[2][3][100001];
