class Solution {
  int n, m;

  bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

public:
  int maxDistance(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          q.push({i, j});
          grid[i][j] = 0;
        } else
          grid[i][j] = -1;
      }
    }
    if (q.empty() || q.size() == n * m) return -1;

    vector<int> offset_x{0, 0, 1, -1}, offset_y{1, -1, 0, 0};

    int res = 0;
    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      res = max(res, grid[a][b]);
      for (int i = 0; i < 4; i++) {
        int x = a + offset_x[i];
        int y = b + offset_y[i];
        if (!valid(x, y) || grid[x][y] >= 0) continue;
        grid[x][y] = grid[a][b] + 1;
        q.push({x, y});
      }
    }

    return res;
  }
};
