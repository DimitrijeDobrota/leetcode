// DP solution
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < amount; i++) {
            if (dp[i] == INT_MAX) continue;
            for (int coin : coins)
                if ((long long)coin + i <= amount) dp[coin + i] = min(dp[coin + i], dp[i] + 1);
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
