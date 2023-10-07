
// Top-down
class Solution {
    static const int MOD = 1e9 + 7;
    static int dp[51][101][51];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int numOfArrays(const int n, const int m, int k, int c = 0, int maxi = 0) {
        if (c == n) return k == 0;
        if (k < 0) return 0;
        if (dp[c][maxi][k] != -1) return dp[c][maxi][k];

        int res = 0;
        for (int i = 1; i <= maxi; i++) {
            res = (res + numOfArrays(n, m, k, c + 1, maxi)) % MOD;
        }

        for (int i = maxi + 1; i <= m; i++) {
            res = (res + numOfArrays(n, m, k - 1, c + 1, i)) % MOD;
        }

        return dp[c][maxi][k] = res;
    }
};

int Solution::dp[51][101][51];

// Bottom-up
class Solution {
    static const int MOD = 1e9 + 7;

  public:
    int numOfArrays(const int n, const int m, int k) {
        vector<vector<int>> dp(vector(m + 1, vector(k + 1, 0)));
        vector<vector<int>> pdp(vector(m + 1, vector(k + 1, 0)));
        for (int num = 0; num <= m; num++)
            pdp[num][0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int maxi = m; maxi >= 0; maxi--) {
                for (int remain = 0; remain <= k; remain++) {
                    int res = 0;
                    for (int num = 1; num <= maxi; num++) {
                        res = (res + pdp[maxi][remain]) % MOD;
                    }

                    if (remain > 0) {
                        for (int num = maxi + 1; num <= m; num++) {
                            res = (res + pdp[num][remain - 1]) % MOD;
                        }
                    }

                    dp[maxi][remain] = res;
                }
            }
            pdp = dp;
        }
        return dp[0][k];
    }
};
