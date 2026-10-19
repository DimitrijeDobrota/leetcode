class Solution {
  public:
    vector<int> targetIndices(const vector<int> &nums, int target) const {
        const int first = std::ranges::count_if(nums, std::bind_front(std::greater{}, target));
        const int last = std::ranges::count_if(nums, std::bind_front(std::greater_equal{}, target));
        return std::views::iota(first, last) | std::ranges::to<std::vector>();
    }
};
