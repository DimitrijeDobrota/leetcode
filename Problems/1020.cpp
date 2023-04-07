class Solution {
  int n, m;
  bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

  int flood_fill(vector<vector<int>> &grid, int x, int y) {
    grid[x][y] = 0;
    int count = 1;
    if (valid(x + 1, y) && grid[x + 1][y]) count += flood_fill(grid, x + 1, y);
    if (valid(x - 1, y) && grid[x - 1][y]) count += flood_fill(grid, x - 1, y);
    if (valid(x, y + 1) && grid[x][y + 1]) count += flood_fill(grid, x, y + 1);
    if (valid(x, y - 1) && grid[x][y - 1]) count += flood_fill(grid, x, y - 1);
    return count;
  }

public:
  int numEnclaves(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      if (grid[i][0]) flood_fill(grid, i, 0);
      if (grid[i][m - 1]) flood_fill(grid, i, m - 1);
    }
    for (int i = 0; i < m; i++) {
      if (grid[0][i]) flood_fill(grid, 0, i);
      if (grid[n - 1][i]) flood_fill(grid, n - 1, i);
    }

    int res = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (!grid[i][j]) continue;
        res += flood_fill(grid, i, j);
      }
    }

    return res;
  }
};
