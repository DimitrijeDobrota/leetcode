class Solution {
  int n;

  bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    n = matrix.size();

    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        int mini = INT_MAX;
        for (int k = -1; k <= 1; k++) {
          int x = i + 1;
          int y = j + k;
          if (!valid(x, y)) continue;
          mini = min(mini, matrix[x][y]);
        }
        matrix[i][j] += mini;
      }
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++) mini = min(mini, matrix[0][i]);
    return mini;
  }
};
