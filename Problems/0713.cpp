class Solution {
public:
    int numSubarrayProductLessThanK(const vector<int>& nums, int k) const {
        std::size_t product = 1;
        std::size_t result = 0;

        std::size_t left = 0; 
        for (const auto right: std::views::iota(0UZ, std::size(nums))) {
            product *= nums[right];

            while (left <= right && product >= k) {
                product /= nums[left++];
            }

            result += right - left + 1;
        }
        return result;
    }
};