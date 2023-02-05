class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> mat(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    q.push({0, 0}), mat[0][0] = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      mat[x][y] += grid[x][y];
      if (x + 1 < n) {
        if (mat[x + 1][y] == INT_MAX) q.push({x + 1, y});
        mat[x + 1][y] = min(mat[x + 1][y], mat[x][y]);
      }
      if (y + 1 < m) {
        if (mat[x][y + 1] == INT_MAX) q.push({x, y + 1});
        mat[x][y + 1] = min(mat[x][y + 1], mat[x][y]);
      }
    }

    return mat.back().back();
  }
};
