class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int target) const {
        const auto sum = std::ranges::fold_left(nums, 0, std::plus{});

        if (target < -sum || target > sum) return 0;
        if ((sum - target) % 2 != 0) return 0;

        const auto goal = (sum - target) / 2;
        std::vector<int> dp(goal + 1, 0);

        dp[0] = 1;
        for (const auto num: nums) {
            if (num > goal) continue;
            for (const auto g: std::views::iota(num, goal + 1) | std::views::reverse) {
                dp[g] += dp[g - num];
            }
        }

        return dp[goal];
    }
};