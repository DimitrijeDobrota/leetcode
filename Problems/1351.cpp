class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), res = 0;
    int i = n - 1, j = 0, cnt = 0;
    while (i >= 0 && j < m) {
      if (grid[i][j] < 0) {
        res += m - j;
        i--;
      } else {
        j++;
      }
    }
    return res;
  }
};
