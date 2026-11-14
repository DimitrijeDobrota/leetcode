class Solution {
public:
    std::vector<int> nextGreaterElements(const std::vector<int>& nums) const {
        const auto n = std::size(nums);
        std::vector<int> result(n, -1);
        std::vector<int> stack; 

        for (const auto [idx, num]: std::views::enumerate(nums)) {
            while (!std::empty(stack) && num > nums[stack.back()]) {
                result[stack.back()] = num;
                stack.pop_back();
            }
            stack.emplace_back(idx);
        }

        for (const auto num: nums) {
            while (!std::empty(stack) && num > nums[stack.back()]) {
                result[stack.back()] = num;
                stack.pop_back();
            }
        }

        return result;
    }
};