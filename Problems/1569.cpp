class Solution {
    static constexpr std::size_t max_elem = 1'001;
    static constexpr int MOD = 1E9 + 7;

    inline static std::array<long long, max_elem * (max_elem + 1) / 2> table{};
    inline static std::once_flag table_once;

    static long long& lookup(std::size_t row, std::size_t col) {
        return table[row * (row + 1) / 2 + col];
    }

    static void generate(int numRows) {
        lookup(0, 0) = 1;
        for (int i = 1; i < numRows; i++) {
            lookup(i, 0) = lookup(i, i) = 1;
            for (int j = 1; j < i; j++) {
                lookup(i, j) = (lookup(i - 1, j - 1) + lookup(i - 1, j)) % MOD;
            }
        }
    }

    long long rec(std::span<int> range) {
        if (std::size(range) <= 2) return 1;

        const int root = range[0];
        const std::span rest = range.subspan(1);

        auto pred = std::bind_front(std::greater<int>{}, root);
        auto mid = std::ranges::stable_partition(rest, pred);
        const std::size_t n = std::distance(std::begin(rest), std::begin(mid));

        long long result = lookup(std::size(range) - 1, n);
        result = result * rec(rest.first(n)) % MOD; 
        result = result * rec(rest.subspan(n)) % MOD; 
        return result;
    }

public:
    Solution() {
        std::call_once(table_once, [] {
            generate(max_elem);
        });
    }

    int numOfWays(vector<int>& nums) {
        return (rec(nums) + MOD - 1) % MOD;
    }
};