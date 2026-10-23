class Solution {
  public:
    int sortPermutation(const vector<int> &nums) const {
        std::size_t result = -1;
        for (const auto [idx, num] : std::views::enumerate(nums)) {
            if (idx != num) result &= num;
        }
        return result != -1 ? result : 0;
    }
};
