class Solution {
    static int dp[201][201];

    static int rec(int a, int b) {
        if (a >= b) return 0;
        if (dp[a][b] != 0) return dp[a][b];

        int res = INT_MAX;
        for (int i = (a + b) / 2; i <= b; i++) {
            res = min(i + max(rec(i + 1, b), rec(a, i - 1)), res);
        }

        return dp[a][b] = res;
    }

  public:
    int getMoneyAmount(int n) const {
        memset(dp, 0x00, sizeof(dp));
        return rec(1, n);
    }
};

int Solution::dp[201][201];
