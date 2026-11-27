class Solution {
public:
    bool canPartition(const std::vector<int>& nums) const {
        const auto sum = std::ranges::fold_left(nums, 0, std::plus{});
        if (sum % 2 == 1) return false;

        const auto goal = sum / 2;
        std::vector<int> dp(goal + 1, 0);

        dp[0] = true;
        for (const auto num: nums) {
            if (num > goal) continue;
            for (const auto g: std::views::iota(num, goal + 1) | std::views::reverse) {
                if (!dp[g - num]) continue;
                dp[g] = true;
            }
        }

        return dp[goal] != 0;
    }
};