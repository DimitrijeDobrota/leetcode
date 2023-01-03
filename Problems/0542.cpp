class Solution {
  int m, n;
  vector<pair<int, int>> offset = {
      {-1,  0},
      { 1,  0},
      { 0, -1},
      { 0,  1}
  };

  int valid(int sr, int sc) { return sr >= 0 && sr < m && sc >= 0 && sc < n; }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    m = mat.size();
    n = mat[0].size();

    vector<vector<int>> res(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          res[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [sr, sc] = q.front();
      q.pop();
      for (auto &p : offset) {
        int nsr = sr + p.first;
        int nsc = sc + p.second;
        if (valid(nsr, nsc)) {
          if (res[nsr][nsc] > res[sr][sc] + 1) {
            res[nsr][nsc] = res[sr][sc] + 1;
            q.push({nsr, nsc});
          }
        }
      }
    }

    return res;
  }
};
