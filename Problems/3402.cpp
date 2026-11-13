class Solution {
  public:
    int minimumOperations(const std::vector<std::vector<int>> &grid) const {
        int result = 0;
        for (const auto j : std::views::iota(0UZ, std::size(grid[0]))) {
            auto prev = -1;
            for (const auto i : std::views::iota(0UZ, std::size(grid))) {
                prev = std::max(prev + 1, grid[i][j]);
                result += prev - grid[i][j];
            }
        }
        return result;
    }
};
