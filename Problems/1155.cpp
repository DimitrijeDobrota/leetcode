class Solution {
    static const int MOD = 1E9 + 7;
    static int dp[31][1001];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int numRollsToTarget(int n, int k, int target, int crnt = 0) {
        if (target < 0) return 0;
        if (crnt == n) return target == 0;
        if (dp[crnt][target] != -1) return dp[crnt][target];
        int res = 0;
        for (int i = 1; i <= k; i++) {
            res = (res + numRollsToTarget(n, k, target - i, crnt + 1)) % MOD;
        }
        return dp[crnt][target] = res;
    }
};

int Solution::dp[31][1001];
