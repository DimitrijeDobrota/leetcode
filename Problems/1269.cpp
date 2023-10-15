// Top-down DP
class Solution {
    static const int MOD = 1E9 + 7;
    int dp[501][501];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int numWays(const int steps, const int arrLen, const int crnt = 0) {
        if (steps == 0) return crnt == 0;
        if (dp[crnt][steps] != -1) return dp[crnt][steps];

        int res = numWays(steps - 1, arrLen, crnt);
        if (crnt > 0) res = (res + numWays(steps - 1, arrLen, crnt - 1)) % MOD;
        if (crnt < arrLen - 1) res = (res + numWays(steps - 1, arrLen, crnt + 1)) % MOD;

        return dp[crnt][steps] = res;
    }
};

// Space optimized, bottom-up DP
class Solution {
    static const int MOD = 1E9 + 7;
    static int dp[501], pdp[501];

  public:
    int numWays(const int steps, int arrLen) {
        memset(pdp, 0x00, sizeof(pdp));
        arrLen = min(arrLen, steps), pdp[0] = 1;
        for (int remain = 1; remain <= steps; remain++) {
            for (int crnt = arrLen - 1; crnt >= 0; crnt--) {
                int res = pdp[crnt];
                if (crnt > 0) res = (res + pdp[crnt - 1]) % MOD;
                if (crnt < arrLen - 1) res = (res + pdp[crnt + 1]) % MOD;
                dp[crnt] = res;
            }
            swap(dp, pdp);
        }
        return pdp[0];
    }
};

int Solution::dp[501];
int Solution::pdp[501];
