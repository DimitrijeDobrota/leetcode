class Solution {
  public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) const {
        const int n = size(grid), m = size(grid[0]);

        for (int l = 0; l < n / 2 && l < m / 2; l++) {
            const int elems = (m + n - 4 * l - 2) * 2;
            for (int count = 0; count < k % elems; count++) {
                const int tmp = grid[l][l];
                for (int j = l + 1; j < m - l; j++)
                    grid[l][j - 1] = grid[l][j];
                for (int i = l + 1; i < n - l; i++)
                    grid[i - 1][m - l - 1] = grid[i][m - l - 1];
                for (int j = m - l - 2; j >= l; j--)
                    grid[n - l - 1][j + 1] = grid[n - l - 1][j];
                for (int i = n - l - 2; i >= l; i--)
                    grid[i + 1][l] = grid[i][l];
                grid[l + 1][l] = tmp;
            }
        }

        return grid;
    }
};
