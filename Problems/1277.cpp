class Solution {
public:
  int countSquares(const vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> count(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        count[i][j] = matrix[i - 1][j - 1] + count[i - 1][j] + count[i][j - 1] -
                      count[i - 1][j - 1];
      }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x = i, y = j;
        for (int k = 1, x = i, y = j; x <= n && y <= m; x++, y++, k++) {
          int sum = count[x][y] - count[i - 1][y] - count[x][j - 1] +
                    count[i - 1][j - 1];
          if (sum != k * k) break;
          res++;
        }
      }
    }

    return res;
  }
};
