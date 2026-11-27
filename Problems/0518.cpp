class Solution {
public:
    int change(int amount, const std::vector<int>& coins) const {
        std::vector<unsigned> dp(amount + 1, 0);
        
        dp[0] = 1;
        for (const auto coin: coins) {
            if (coin > amount) continue;
            for (const auto a: std::views::iota(coin, amount + 1)) {
                dp[a] += dp[a - coin];
            }
        }

        return dp[amount];
    }
};