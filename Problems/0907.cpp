class Solution {
public:
    int sumSubarrayMins(const vector<int>& arr) const {
        static constexpr int mod = 1e9 + 7;
        std::vector<std::pair<int, int>> stack;
        long long result = 0;
        long long sum = 0;

        for (const auto num: arr) {
            int count = 1;
            while (!std::empty(stack) && num <= stack.back().first) {
                const auto [val, occ] = stack.back();
                stack.pop_back();

                sum -= 1LL * val * occ;
                count += occ;
            }
            stack.emplace_back(num, count);

            sum += 1LL * count * num;
            result = (result + sum) % mod;
        }

        return result; 
    }
};