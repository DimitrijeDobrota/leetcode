class Solution {
  public:
    int longestMonotonicSubarray(const vector<int> &nums) const {
        int increase = 1;
        int decrease = 1;
        int result = 1;
        for (const auto idx : std::views::iota(1UZ, std::size(nums))) {
            increase = nums[idx] > nums[idx - 1] ? increase + 1 : 1;
            decrease = nums[idx] < nums[idx - 1] ? decrease + 1 : 1;
            result = std::max({result, increase, decrease});
        }
        return result;
    }
};
