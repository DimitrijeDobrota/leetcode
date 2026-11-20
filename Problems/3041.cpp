class Solution {
  public:
    int maxSelectedElements(std::vector<int> &nums) const {
        std::ranges::sort(nums);

        int result = 0;
        std::unordered_map<int, int> dp;
        for (const auto x : nums) {
            dp[x + 1] = std::max(dp[x + 1], dp[x] + 1);
            dp[x] = std::max(dp[x], dp[x - 1] + 1);

            result = std::max({result, dp[x], dp[x + 1]});
        }

        return result;
    }
};
