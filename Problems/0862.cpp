#include "../Templates/monotonic_queue.hpp"
#include "../Templates/indexed_compare.hpp"

class Solution {
public:
    int shortestSubarray(const vector<int>& nums, int k) const {
        static constexpr std::size_t max_size = 100'001;
        static std::array<std::int64_t, max_size> prefix{};
        const auto dominated = indexed_less_equal{prefix};
        static monotonic_queue<std::size_t, max_size, decltype(dominated)> candid(dominated);

        std::int64_t acc = 0;
        const auto n = std::size(nums);
        for (std::size_t i = 0; i < n ; i++) {
            prefix[i + 1] = acc += nums[i];
        }

        std::size_t result = n + 1;
        for (std::size_t right = 0; right <= n; right++) {
            while (!std::empty(candid) && prefix[right] - prefix[candid.front()] >= k) {
                result = std::min(result, right - candid.front());
                candid.pop();
            }
            candid.push(right);
        }

        return result <= n ? result : -1;
    }
};