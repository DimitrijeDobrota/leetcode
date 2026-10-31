class Solution {
  public:
    int uniquePaths(const vector<vector<int>> &grid) const {
        const auto n = std::size(grid);
        const auto m = std::size(grid[0]);

        std::vector<int> down(m, 0);
        down[m - 1] = 1;
        for (std::size_t i = n - 1; i < n; i--) {
            int right = 0;
            for (std::size_t j = m - 1; j < m; j--) {
                if (grid[i][j] == 1) {
                    std::swap(down[j], right);
                    continue;
                }
                const auto total = (down[j] + right) % (int)(1e9 + 7);
                down[j] = right = total;
            }
        }

        return down[0];
    }
};
