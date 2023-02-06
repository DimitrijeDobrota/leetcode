class Solution {
  typedef vector<vector<int>> Mat;
  int n;

  void swap_group(Mat &matrix, int x, int y) {
    swap(matrix[x][y], matrix[y][n - x - 1]);
    swap(matrix[n - x - 1][n - y - 1], matrix[n - y - 1][x]);
    swap(matrix[x][y], matrix[n - x - 1][n - y - 1]);
  }

public:
  void rotate(Mat &matrix) {
    n = matrix.size();
    for (int i = 0; i <= n / 2; i++)
      for (int j = i; j < n - i - 1; j++) swap_group(matrix, i, j);
  }
};
