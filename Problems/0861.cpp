class Solution {
public:
  int matrixScore(const vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    unordered_set<int> flipped;
    for (int i = 0; i < n; i++) {
      if (grid[i][0]) continue;
      flipped.insert(i);
    }

    int res = n * (1 << m - 1);
    for (int j = 1; j < m; j++) {
      int count = 0;
      for (int i = 0; i < n; i++)
        count += flipped.count(i) ? !grid[i][j] : grid[i][j];
      res += max(count, n - count) * (1 << m - j - 1);
    }
    return res;
  }
};
