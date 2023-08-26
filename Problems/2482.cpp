class Solution {
  public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> col(n, 0), row(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col[i] += grid[i][j];
                row[j] += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = 2 * (col[i] + row[j]) - (m + n);
            }
        }

        return grid;
    }
};
