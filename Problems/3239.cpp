class Solution {
  public:
    int minFlips(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        int row = 0, col = 0;

        for (int i = 0; i < n; i++) {
            int a = 0, b = m - 1;
            while (a < b)
                row += grid[i][a++] != grid[i][b--];
        }

        for (int j = 0; j < m; j++) {
            int a = 0, b = n - 1;
            while (a < b)
                col += grid[a++][j] != grid[b--][j];
        }

        return min(row, col);
    }
};
