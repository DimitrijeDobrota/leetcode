class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size(), res = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!i || !j || matrix[i][j] == '0') {
          dp[i][j] = matrix[i][j] - '0';
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
        res = max(res, dp[i][j]);
      }
    }
    return res * res;
  }
};
