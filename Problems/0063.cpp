class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int dp[101][101] = {0};
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();

    for (int i = 0, flag = 0; i < n; i++) {
      if (flag || obstacleGrid[i][0])
        flag = true;
      else
        dp[i][0] = 1;
    }

    for (int i = 0, flag = 0; i < m; i++) {
      if (flag || obstacleGrid[0][i])
        flag = true;
      else
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n - 1][m - 1];
  }
};
