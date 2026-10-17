class Solution {
    static constexpr std::size_t max_n = 100'000;

    static constexpr int digit_sum(int num) {
        int sum = 0;
        while (num > 0)
            sum += num % 10, num /= 10;
        return sum;
    }

  public:
    int minSwaps(const vector<int> &nums) const {
        static std::array<int, max_n> idx_storage;
        static std::array<int, max_n> sum_storage;

        std::span idxs{std::data(idx_storage), std::size(nums)};
        std::span sums{std::data(sum_storage), std::size(nums)};

        std::ranges::transform(nums, std::begin(sums), digit_sum);

        std::ranges::iota(idxs, 0);
        std::ranges::sort(idxs, std::less{}, [&](int idx) { return std::pair{sums[idx], nums[idx]}; });

        int swaps = std::size(nums);
        for (const std::size_t start : std::views::iota(0uz, std::size(nums))) {
            if (idxs[start] == -1) continue;
            for (auto current = start; idxs[current] != -1;)
                current = std::exchange(idxs[current], -1);
            swaps--;
        }
        return swaps;
    }
};
