class Solution {
  public:
    int minimumSumSubarray(const vector<int> &nums, std::size_t l, std::size_t r) const {
        const auto n = std::size(nums);
        std::vector<int> prefix(n + 1, 0);

        for (const auto [idx, num] : std::views::enumerate(nums)) {
            prefix[idx + 1] = prefix[idx] + num;
        }

        static const auto inf = std::numeric_limits<int>::max();
        int result = inf;
        for (const auto size : std::views::iota(l, r + 1UZ)) {
            for (const auto idx : std::views::iota(size, n + 1UZ)) {
                const auto sum = prefix[idx] - prefix[idx - size];
                if (sum <= 0) continue;
                result = std::min(result, sum);
            }
        }

        return result != inf ? result : -1;
    }
};

class Solution {
  public:
    int minimumSumSubarray(const vector<int> &nums, std::size_t l, std::size_t r) const {
        const auto n = std::size(nums);
        std::vector<int> prefix(n + 1, 0);

        for (const auto [idx, num] : std::views::enumerate(nums)) {
            prefix[idx + 1] = prefix[idx] + num;
        }

        static const auto inf = std::numeric_limits<int>::max();
        int result = inf;

        std::multiset<int> eligible;
        for (const auto j : std::views::iota(l, n + 1UZ)) {
            eligible.insert(prefix[j - l]);

            if (j > r) {
                eligible.erase(eligible.find(prefix[j - r - 1]));
            }

            auto it = eligible.lower_bound(prefix[j]);
            if (it == std::begin(eligible)) continue;

            result = std::min(result, prefix[j] - *std::prev(it));
        }

        return result != inf ? result : -1;
    }
};
