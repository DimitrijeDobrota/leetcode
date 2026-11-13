class Solution {
public:
    vector<int> runningSum(vector<int> nums) const {
        for (const auto i: std::views::iota(1UZ, std::size(nums))) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};