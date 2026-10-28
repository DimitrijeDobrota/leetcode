class Solution {
  public:
    int minCost(const std::vector<std::vector<int>> &grid) const {
        const auto n = std::size(grid);
        const auto m = std::size(grid[0]);

        std::array<std::bitset<1024>, 1024> dp;
        const auto index = [&](int i, int j) -> auto & { return dp[i * m + j]; };

        index(0, 0).set(grid[0][0]);
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < m; j++) {
                std::bitset<1024> incoming;
                if (i > 0) incoming |= index(i - 1, j);
                if (j > 0) incoming |= index(i, j - 1);
                for (std::size_t k = 0; k < 1024; k++) {
                    if (incoming.test(k)) index(i, j).set(grid[i][j] ^ k);
                }
            }
        }

        for (std::size_t k = 0; k < 1024; k++) {
            if (index(n - 1, m - 1).test(k)) {
                return k;
            }
        }
        return 0;
    }
};
