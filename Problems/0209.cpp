class Solution {
public:
    int minSubArrayLen(int target, const vector<int>& nums) const {
        const auto n = std::size(nums);
        std::size_t result = n + 1;
        std::size_t sum = 0;

        std::size_t left = 0;
        for (const auto right: std::views::iota(0UZ, n)) {
            sum += nums[right];

            while (sum >= target) {
                result = std::min(result, right - left + 1UZ);
                sum -= nums[left++];
            }
        }
        return result != n + 1 ? result : 0; 
    }
};