class Solution {
public:
    vector<int> nextGreaterElement(const std::vector<int>& nums1, const std::vector<int>& nums2) const {
        std::unordered_map<int, int> next_max;
        std::vector<int> stack;

        for (const auto num: nums2) {
            while (!std::empty(stack) && num > stack.back()) {
                next_max.emplace(stack.back(), num);
                stack.pop_back();
            }
            stack.emplace_back(num);
        }

        std::vector<int> result(std::size(nums1), -1);
        for (const auto [idx, num]: std::views::enumerate(nums1)) {
            if (const auto it = next_max.find(num); it != std::end(next_max)) {
                result[idx] = it->second;
            }
        }
        return result;
    }
};