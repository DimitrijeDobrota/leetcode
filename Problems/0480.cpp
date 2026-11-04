class Solution {
  public:
    std::vector<double> medianSlidingWindow(const std::vector<int> &nums, std::size_t k) const {
        std::multiset<int> high;
        std::multiset<int> low;

        const auto rebalance = [&] {
            if (std::size(low) > std::size(high) + 1) {
                auto it = std::prev(std::end(low));
                high.insert(std::begin(high), low.extract(it));
            } else if (std::size(high) > std::size(low)) {
                auto it = std::begin(high);
                low.insert(std::end(low), high.extract(it));
            }
        };

        const auto insert = [&](int num) {
            if (std::empty(low) || num <= *std::rbegin(low)) {
                low.insert(num);
            } else {
                high.insert(num);
            }
            rebalance();
        };

        const auto erase = [&](int num) {
            if (auto it = low.find(num); it != std::end(low)) {
                low.erase(it);
            } else {
                high.erase(high.find(num));
            }
            rebalance();
        };

        const auto median = [&]() -> double {
            const double lower = *std::rbegin(low);
            return k % 2 == 1 ? lower : (lower + *std::begin(high)) / 2.0;
        };

        for (const auto i : std::views::iota(0UZ, k)) {
            insert(nums[i]);
        }

        std::vector<double> result;
        result.reserve(std::size(nums) - k + 1);
        result.push_back(median());

        for (std::size_t i = k; i < std::size(nums); ++i) {
            erase(nums[i - k]);
            insert(nums[i]);
            result.push_back(median());
        }

        return result;
    }
};
