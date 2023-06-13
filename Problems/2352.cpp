class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int n = grid.size(), res = 0;
    map<vector<int>, int> m;
    for (const auto &vec : grid) m[vec]++;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i < j) swap(grid[i][j], grid[j][i]);

    for (const auto &vec : grid) res += m[vec];
    return res;
  }
};
