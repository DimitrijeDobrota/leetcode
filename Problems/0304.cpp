class NumMatrix {
  int n, m;
  vector<vector<int>> dp;

public:
  NumMatrix(vector<vector<int>> &matrix)
      : n(matrix.size()), m(matrix[0].size()),
        dp(vector<vector<int>>(n, vector<int>(m, 0))) {
    for (int i = 0, sum = 0; i < n; i++) sum = dp[i][0] = matrix[i][0] + sum;
    for (int i = 0, sum = 0; i < m; i++) sum = dp[0][i] = matrix[0][i] + sum;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        dp[i][j] =
            matrix[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int x1, int y1, int x2, int y2) {
    int res = dp[x2][y2];
    if (x1 > 0) res -= dp[x1 - 1][y2];
    if (y1 > 0) res -= dp[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) res += dp[x1 - 1][y1 - 1];
    return res;
  }
};
