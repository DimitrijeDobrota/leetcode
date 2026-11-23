class Solution {
public:
    long long maximumSumOfHeights(const std::vector<int>& maxHeights) const {
        const auto n = std::size(maxHeights);
        std::vector<std::pair<int, int>> stack;
        std::vector<long long> left(n);
        stack.reserve(n);

        long long sum = 0;
        for (auto&& [num, prefix] : std::views::zip(maxHeights, left)) {
            int count = 1;
            while (!stack.empty() && num < stack.back().first) {
                const auto [height, cnt] = stack.back();
                stack.pop_back();
                sum -= 1LL * cnt * (height - num);
                count += cnt;
            }
            stack.emplace_back(num, count);
            prefix = sum;
            sum += num;
        }

        sum = 0;
        stack.clear();
        long long result = 0;
        for (auto&& [num, prefix] : std::views::zip(maxHeights, left) | std::views::reverse) {
            int count = 1;
            while (!stack.empty() && num < stack.back().first) {
                const auto [height, cnt] = stack.back();
                stack.pop_back();
                sum -= 1LL * cnt * (height - num);
                count += cnt;
            }
            stack.emplace_back(num, count);
            result = std::max(result, prefix + sum + num);
            sum += num;
        }

        return result;
    }
};