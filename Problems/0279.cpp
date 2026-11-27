class Solution {
public:
    int numSquares(int n) const {
        static constexpr auto inf = std::numeric_limits<int>::max();
        const int sqrt = std::sqrt(n);
        std::vector<int> dp(n + 1, inf);

        dp[0] = 0;
        for (const auto num: std::views::iota(1, sqrt + 1)) {
            const auto square = num * num;
            for (const auto g: std::views::iota(square, n + 1)) {
                dp[g] = std::min(dp[g], 1 + dp[g - square]);
            }
        }
        
        return dp[n];
    }
};