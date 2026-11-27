class Solution {
public:
    int coinChange(const std::vector<int>& coins, long long amount) const {
        static constexpr auto inf = std::numeric_limits<int>::max();
        std::vector<long long> dp(amount + 1, inf);

        dp[0] = 0;
        for (const auto coin: coins) {
            if (coin > amount) continue;
            for (const auto a: std::views::iota(coin, amount + 1)) {
                dp[a] = std::min(dp[a], 1 + dp[a - coin]);
            }
        }

        return dp[amount] != inf ? dp[amount] : -1;
    }
};