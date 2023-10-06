// DP
class Solution {
    static int dp[64];

    int rec(const int n) const {
        if (n <= 3) return n;
        if (dp[n] != -1) return dp[n];
        int res = n;
        for (int i = 2; i < n; i++)
            res = max(res, i * rec(n - i));
        return dp[n] = res;
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int integerBreak(const int n) const {
        if (n <= 3) return n - 1;
        return rec(n);
        ;
    }
};

int Solution::dp[64];
