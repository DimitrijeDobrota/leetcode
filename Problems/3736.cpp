class Solution {
  public:
    int minMoves(const std::vector<int> &nums) const {
        const auto max = std::ranges::max(nums);
        const auto sum = std::ranges::fold_left(nums, 0, std::plus<int>{});
        return std::size(nums) * max - sum;
    }
};
