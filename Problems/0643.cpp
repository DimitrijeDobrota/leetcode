class Solution {
public:
    double findMaxAverage(const vector<int>& nums, std::size_t k) const {
        int sum = 0;
        for (const auto num: nums | std::views::take(k)) sum += num;
        
        auto maxSum = sum;
        for (const auto idx: std::views::iota(k, std::size(nums))) {
            sum -= nums[idx - k];
            sum += nums[idx];
            maxSum = std::max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};