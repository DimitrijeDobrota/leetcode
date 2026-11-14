class Solution {
public:
    int largestRectangleArea(const std::vector<int>& heights) const {
        const auto n = std::size(heights);
        std::vector<int> right(n);
        std::vector<int> left(n);

        std::vector<int> stack;

        for (const auto [idx, height]: std::views::enumerate(heights)) {
            left[idx] = idx;
            while (!std::empty(stack) && height <= heights[stack.back()]) {
                left[idx] = left[stack.back()];
                stack.pop_back();
            }
            stack.push_back(idx);
        }

        for (const auto [idx, height]: std::views::enumerate(heights) | std::views::reverse) {
            right[idx] = idx;
            while (!std::empty(stack) && height <= heights[stack.back()]) {
                right[idx] = right[stack.back()];
                stack.pop_back();
            }
            stack.push_back(idx);
        }

        int result = 0;
        for (const auto idx: std::views::iota(0UZ, n)) {
            result = std::max(result, (right[idx] - left[idx] + 1) * heights[idx]);
        }
        return result;
    }
};