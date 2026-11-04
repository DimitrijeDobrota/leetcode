class Solution {
  public:
    long long minOperations(std::vector<int> &nums, std::size_t x, std::size_t k) const {
        std::multiset<int> high;
        std::multiset<int> low;
        long long sum_low = 0;
        long long sum_high = 0;

        const auto rebalance = [&] {
            if (std::size(low) > std::size(high) + 1) {
                auto it = std::prev(std::end(low));
                sum_high += *it;
                sum_low -= *it;
                high.insert(std::begin(high), low.extract(it));
            } else if (std::size(high) > std::size(low)) {
                auto it = std::begin(high);
                sum_high -= *it;
                sum_low += *it;
                low.insert(std::end(low), high.extract(it));
            }
        };

        const auto insert = [&](int num) {
            if (std::empty(low) || num <= *std::rbegin(low)) {
                low.insert(num);
                sum_low += num;
            } else {
                high.insert(num);
                sum_high += num;
            }
            rebalance();
        };

        const auto erase = [&](int num) {
            if (auto it = low.find(num); it != std::end(low)) {
                low.erase(it);
                sum_low -= num;
            } else {
                high.erase(high.find(num));
                sum_high -= num;
            }
            rebalance();
        };

        const auto cost = [&]() -> long long {
            const long long median = *std::rbegin(low);
            return median * static_cast<long long>(std::size(low)) - sum_low + sum_high -
                   median * static_cast<long long>(std::size(high));
        };

        for (const auto i : std::views::iota(0UZ, x)) {
            insert(nums[i]);
        }

        const auto n = std::size(nums);
        std::vector<long long> costs;
        costs.reserve(n - x + 1);
        costs.push_back(cost());

        for (std::size_t i = x; i < n; ++i) {
            erase(nums[i - x]);
            insert(nums[i]);
            costs.push_back(cost());
        }

        constexpr auto infinity = std::numeric_limits<long long>::max() / 4;
        std::vector<long long> previous(n + 1, 0);
        std::vector<long long> current(n + 1);

        for (std::size_t count = 1; count <= k; ++count) {
            std::ranges::fill(current, infinity);
            for (std::size_t i = count * x; i <= n; ++i) {
                current[i] = std::min(current[i - 1], previous[i - x] + costs[i - x]);
            }
            std::swap(previous, current);
        }

        return previous[n];
    }
};
