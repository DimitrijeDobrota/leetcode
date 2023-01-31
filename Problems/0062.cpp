class Solution {
public:
  int uniquePaths(int n, int m) {
    vector<vector<int>> mat(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1}), mat[n - 1][m - 1] = 1;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      if (x - 1 >= 0) {
        mat[x - 1][y] += mat[x][y];
        if (mat[x - 1][y] == mat[x][y]) q.push({x - 1, y});
      }
      if (y - 1 >= 0) {
        mat[x][y - 1] += mat[x][y];
        if (mat[x][y - 1] == mat[x][y]) q.push({x, y - 1});
      }
    }
    return mat[0][0];
  }
};
