class Solution {
  public:
    int minPathCost(vector<vector<int>> &grid, const vector<vector<int>> &moveCost) {
        const int n = grid.size(), m = grid[0].size();

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int res = INT_MAX;
                for (int k = 0; k < m; k++) {
                    res = min(res, grid[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                grid[i][j] += res;
            }
        }

        return *min_element(begin(grid[0]), end(grid[0]));
    }
};
