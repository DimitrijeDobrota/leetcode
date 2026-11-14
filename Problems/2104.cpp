class Solution {
public:
    long long subArrayRanges(const std::vector<int>& nums) const {
        std::vector<std::pair<int, int>> stack;
        long long result = 0;
        long long sum = 0;

        for (const auto num: nums) {
            int count = 1;
            while (!std::empty(stack) && num >= stack.back().first) {
                const auto [val, occ] = stack.back();
                stack.pop_back();
                sum -= 1LL * val * occ;
                count += occ;
            }
            stack.emplace_back(num, count);
            sum += 1LL * count * num;
            result += sum;
        }

        sum = 0;
        stack.clear();
        for (const auto num: nums) {
            int count = 1;
            while (!std::empty(stack) && num <= stack.back().first) {
                const auto [val, occ] = stack.back();
                stack.pop_back();
                sum -= 1LL * val * occ;
                count += occ;
            }
            stack.emplace_back(num, count);
            sum += 1LL * count * num;
            result -= sum;
        }

        return result;
    }
};