class Solution {
  static const constexpr int offs_x[] = {1, 0, -1, 0};
  static const constexpr int offs_y[] = {0, 1, 0, -1};

  int n;

  bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }

public:
  int shortestBridge(vector<vector<int>> &grid) {
    queue<pair<int, int>> dq1, dq2;
    n = grid.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!grid[i][j]) continue;
        dq1.push({i, j});
        grid[i][j] = 2;
        goto parse;
      }
    }

    return -1;

  parse:
    while (!dq1.empty()) {
      auto [i, j] = dq1.front();
      dq1.pop();
      for (int k = 0; k < 4; k++) {
        int a = i + offs_x[k], b = j + offs_y[k];
        if (!valid(a, b)) continue;
        if (grid[a][b] == 1)
          dq1.push({a, b});
        else if (grid[a][b] == 0)
          dq2.push({a, b});
        grid[a][b] = 2;
      }
    }

    for (int lvl = 1; !dq2.empty(); lvl++) {
      for (int k = dq2.size(); k > 0; k--) {
        auto [i, j] = dq2.front();
        dq2.pop();
        for (int k = 0; k < 4; k++) {
          int a = i + offs_x[k], b = j + offs_y[k];
          if (!valid(a, b)) continue;
          if (grid[a][b] == 1)
            return lvl;
          else if (grid[a][b] == 0)
            dq2.push({a, b});
          grid[a][b] = 2;
        }
      }
    }

    return -1;
  }
};
