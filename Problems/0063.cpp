class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<long>> mat(n, vector<long>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (obstacleGrid[i][j]) mat[i][j] = -1;

    if (mat[n - 1][m - 1] == -1) return 0;
    if (mat[0][0] == -1) return 0;

    queue<pair<int, int>> q;
    q.push({n - 1, m - 1}), mat[n - 1][m - 1] = 1;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      if (x - 1 >= 0 && mat[x - 1][y] != -1) {
        mat[x - 1][y] += mat[x][y];
        if (mat[x - 1][y] == mat[x][y]) q.push({x - 1, y});
      }
      if (y - 1 >= 0 && mat[x][y - 1] != -1) {
        mat[x][y - 1] += mat[x][y];
        if (mat[x][y - 1] == mat[x][y]) q.push({x, y - 1});
      }
    }
    return (int)mat[0][0];
  }
};
