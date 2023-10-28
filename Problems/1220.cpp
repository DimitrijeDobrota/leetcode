class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int countVowelPermutation(int n) {
        long dp[5], pdp[5] = {1, 1, 1, 1, 1};
        for (int i = 1; i < n; i++) {
            dp[0] = (pdp[1] + pdp[2] + pdp[4]) % MOD;
            dp[1] = (pdp[0] + pdp[2]) % MOD;
            dp[2] = (pdp[1] + pdp[3]) % MOD;
            dp[3] = (pdp[2]) % MOD;
            dp[4] = (pdp[2] + pdp[3]) % MOD;
            swap(dp, pdp);
        }
        int res = 0;
        for (int i = 0; i < 5; i++)
            res = (res + pdp[i]) % MOD;
        return res;
    }
};
