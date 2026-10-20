class Solution {
  public:
    int sortableIntegers(const vector<int> &nums) const {
        static std::array<std::int32_t, 100'000> suffix_drop;
        static std::array<std::size_t, 100'000> next_drop;
        const std::size_t n = std::size(nums);

        next_drop[n - 1] = n;
        for (std::size_t i = n - 1; i > 0; i--) {
            const bool is_drop = nums[i - 1] > nums[i];
            suffix_drop[i - 1] = suffix_drop[i] + is_drop;
            next_drop[i - 1] = is_drop ? i - 1 : next_drop[i];
        }

        const auto check = [&](std::size_t candid) -> int {
            int previous_max = 0;

            for (std::size_t start = 0; start < n; start += candid) {
                const std::size_t end = start + candid;
                const int drop = suffix_drop[start] - suffix_drop[end - 1];

                if (drop > 1) return 0;

                int min = nums[start];
                int max = nums[end - 1];

                if (drop == 1) {
                    if (nums[end - 1] > nums[start]) return 0;
                    min = nums[next_drop[start] + 1];
                    max = nums[next_drop[start]];
                }

                if (start > 0 && previous_max > min) return 0;

                previous_max = max;
            }

            return candid;
        };

        int res = 0;
        std::size_t i = 1;
        for (; i * i < n; i++) {
            if (n % i != 0) continue;
            res += check(i) + check(n / i);
        }
        if (i * i == n) res += check(i);

        return res;
    }
};
