static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

class Solution {
  public:
    int minimumArea(const vector<vector<int>> &grid) const {
        int minix = INT_MAX, maxix = INT_MIN;
        int miniy = INT_MAX, maxiy = INT_MIN;

        for (int i = 0; i < size(grid); i++) {
            for (int j = 0; j < size(grid[0]); j++) {
                if (!grid[i][j]) continue;
                minix = min(minix, i);
                maxix = max(maxix, i);
                miniy = min(miniy, j);
                maxiy = max(maxiy, j);
            }
        }

        return (maxix - minix + 1) * (maxiy - miniy + 1);
    }
};
