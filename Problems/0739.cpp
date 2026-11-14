class Solution {
public:
    std::vector<int> dailyTemperatures(const vector<int>& temperatures) const {
        std::vector<int> result(std::size(temperatures), 0);
        std::vector<int> stack;

        for (const auto [idx, temperature]: std::views::enumerate(temperatures)) {
            while (!std::empty(stack) && temperature > temperatures[stack.back()]) {
                result[stack.back()] = idx - stack.back();
                stack.pop_back();
            }
            stack.emplace_back(idx);
        }

        return result;
    }
};
