class Solution {
public:
    int lastStoneWeightII(const std::vector<int>& stones) const {
        const auto sum = std::ranges::fold_left(stones, 0, std::plus{});
        const auto goal = sum / 2;
        std::vector<int> dp(goal + 1, 0);

        dp[0] = 1;
        for (const auto stone: stones) {
            if (stone > goal) continue;
            for (const auto g: std::views::iota(stone, goal + 1) | std::views::reverse) {
                if (!dp[g - stone]) continue;
                dp[g] = true;
            }
        }

        const auto pos = std::ranges::find_last_if(dp, [](int num) { return num != 0; });
        return sum - 2 * std::ranges::distance(dp.begin(), pos.begin());
    }
};