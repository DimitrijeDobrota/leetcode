class Solution {
  public:
    long long getMaxFunctionValue(const std::vector<int> &receiver, long long k) const {
        const auto levels = std::bit_width(static_cast<std::uint64_t>(k));
        const auto n = std::size(receiver);

        std::vector<std::vector<long long>> count(levels, std::vector<long long>(n));
        std::vector<std::vector<int>> jump(levels, std::vector<int>(n));

        jump[0] = receiver;
        std::ranges::iota(count[0], 0);
        for (const auto lvl : std::views::iota(1, levels)) {
            for (const auto player : std::views::iota(0UZ, n)) {
                const auto halfway = jump[lvl - 1][player];
                jump[lvl][player] = jump[lvl - 1][halfway];
                count[lvl][player] = count[lvl - 1][halfway] + count[lvl - 1][player];
            }
        }

        std::size_t result = 0;
        for (auto player : std::views::iota(0UZ, n)) {
            std::size_t total = 0;
            for (std::uint64_t crnt = k; crnt > 0; crnt &= crnt - 1) {
                const auto lvl = std::countr_zero(crnt);
                total += count[lvl][player];
                player = jump[lvl][player];
            }
            total += player;
            result = std::max(result, total);
        }
        return result;
    }
};
