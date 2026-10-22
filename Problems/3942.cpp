class Solution {
  public:
    int minOperations(const vector<int> &nums) const {
        const auto n = std::size(nums);
        if (n == 1) return 0;

        std::size_t drop = 0, rise = 0;
        std::size_t drop_index, rise_index;
        for (std::size_t i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i])
                drop++, drop_index = i;
            else if (nums[i - 1] < nums[i])
                rise++, rise_index = i;
        }
        if (nums.back() > nums.front())
            drop++, drop_index = 0;
        else if (nums.back() < nums.front())
            rise++, rise_index = 0;

        if (drop == 1) return std::min(drop_index, n - drop_index + 2);
        if (rise == 1) return std::min(rise_index + 1, n - rise_index + 1);
        return -1;
    }
};
