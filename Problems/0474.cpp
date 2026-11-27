class Solution {
public:
    int findMaxForm(const std::vector<string>& strs, int m, int n) const {
        std::array<std::array<int, 101>, 101> dp{};

        for (const auto& str: strs) {
            const int zero = std::ranges::count(str, '0');
            const int one = std::ranges::size(str) - zero;

            if (one > n || zero > m) continue;
            for (const auto ones: std::views::iota(one, n + 1) | std::views::reverse) {
                for (const auto zeros: std::views::iota(zero, m + 1) | std::views::reverse) {
                    dp[ones][zeros] = std::max(dp[ones][zeros], 1 + dp[ones - one][zeros - zero]);
                }
            }
        }

        return dp[n][m];
    }
};