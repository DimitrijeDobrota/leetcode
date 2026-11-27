class Solution {
  public:
    int maximumSaleItems(const std::vector<std::vector<int>> &items, int budget) const {
        const auto n = std::size(items);

        std::vector<int> bonus(n, 0);
        for (const auto i : std::views::iota(0UZ, n)) {
            for (const auto j : std::views::iota(i + 1, n)) {
                if (items[j][0] % items[i][0] == 0) bonus[i]++;
                if (items[i][0] % items[j][0] == 0) bonus[j]++;
            }
        }

        std::vector<int> dp(budget + 1, 0);
        for (const auto i : std::views::iota(0UZ, n)) {
            const int price = items[i][1];
            if (price > budget) continue;

            for (const auto b : std::views::iota(price, budget + 1) | std::views::reverse) {
                dp[b] = std::max(dp[b], dp[b - price] + bonus[i] + 1);
            }

            for (const auto b : std::views::iota(price, budget + 1)) {
                dp[b] = std::max(dp[b], dp[b - price] + 1);
            }
        }

        return dp[budget];
    }
};
