class Solution {
  inline int clamp(const int a, const int x, const int y) {
    return min(max(a, x), y);
  }

public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0)), res(n, vector<int>(m, 0));

    for (int i = 0, sum = 0; i < n; i++) sum = dp[i][0] = mat[i][0] + sum;
    for (int i = 0, sum = 0; i < m; i++) sum = dp[0][i] = mat[0][i] + sum;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        dp[i][j] = mat[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x1 = clamp(i - k, 0, n - 1), y1 = clamp(j - k, 0, m - 1);
        int x2 = clamp(i + k, 0, n - 1), y2 = clamp(j + k, 0, m - 1);
        res[i][j] = dp[x2][y2];
        if (x1 > 0) res[i][j] -= dp[x1 - 1][y2];
        if (y1 > 0) res[i][j] -= dp[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) res[i][j] += dp[x1 - 1][y1 - 1];
      }
    }

    return res;
  }
};
