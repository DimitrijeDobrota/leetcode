class Solution {
  pair<int, int> offset[4] = {
      { 0,  1},
      { 1,  0},
      { 0, -1},
      {-1,  0}
  };
  int limit_offset[4] = {1, -1, -1, 1};
  int limit[4] = {0, 0, 0, 0};

  int &m = limit[2], &n = limit[1];

  bool valid(int i, int j) {
    return i >= limit[0] && i <= m && j >= limit[3] && j <= n;
  }

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    int direction = 0;
    int cnt = 0;
    int size;
    int i = 0, j = 0;

    m = matrix.size() - 1;
    n = matrix[0].size() - 1;
    size = (m + 1) * (n + 1);

    while (true) {
      res.push_back(matrix[i][j]);
      if (++cnt == size) break;

      if (!valid(i + offset[direction].first, j + offset[direction].second)) {
        limit[direction] += limit_offset[direction];
        direction = (direction + 1) % 4;
      }

      i += offset[direction].first;
      j += offset[direction].second;
    }

    return res;
  }
};
