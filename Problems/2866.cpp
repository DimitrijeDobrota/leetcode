class Solution {
  public:
    long long maximumSumOfHeights(const std::vector<int> &maxHeights) const {
        const auto n = std::size(maxHeights);
        std::vector<long long> left(n);

        long long sum = 0;
        std::vector<std::pair<int, int>> stack;
        for (const auto [idx, num] : std::views::enumerate(maxHeights)) {
            int count = 1;
            while (!std::empty(stack) && num < stack.back().first) {
                const auto [height, cnt] = stack.back();
                stack.pop_back();
                sum -= 1LL * cnt * (height - num);
                count += cnt;
            }
            stack.emplace_back(num, count);
            sum += num;
            left[idx] = sum;
        }

        sum = 0;
        stack.clear();
        long long result = 0;
        for (const auto [idx, num] : std::views::enumerate(maxHeights) | std::views::reverse) {
            int count = 1;
            while (!std::empty(stack) && num < stack.back().first) {
                const auto [height, cnt] = stack.back();
                stack.pop_back();
                sum -= 1LL * cnt * (height - num);
                count += cnt;
            }
            stack.emplace_back(num, count);
            result = std::max(result, left[idx] + sum);
            sum += num;
        }

        return result;
    }
};
