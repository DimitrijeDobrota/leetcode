class Solution {
  int MOD = 1E9 + 7;
  int dp[1001][1001];

  int n, m;
  bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

  int rec(const vector<vector<int>> &grid, int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    static const int offs_x[4] = {0, 0, 1, -1};
    static const int offs_y[4] = {1, -1, 0, 0};

    int res = 0;
    for (int k = 0; k < 4; k++) {
      int x = i + offs_x[k], y = j + offs_y[k];
      if (!valid(x, y)) continue;
      if (grid[i][j] < grid[x][y]) res = (res + rec(grid, x, y) + 1) % MOD;
    }
    return dp[i][j] = res;
  }

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }
  int countPaths(const vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();

    int res = m * n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) res = (res + rec(grid, i, j)) % MOD;

    return res;
  }
};
