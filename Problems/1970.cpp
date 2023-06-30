class UnionFind {
  int root[20002], size[20002];

public:
  UnionFind() {
    for (int i = 0; i < 20002; i++) {
      root[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    while (x != root[x]) x = root[x] = root[root[x]];
    return x;
  }

  void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      if (size[x] > size[y]) swap(x, y);
      root[x] = y;
      size[y] += size[x];
    }
  }

  bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
  int grid[20000] = {0};

public:
  int latestDayToCross(int row, int col, const vector<vector<int>> &cells) {
    static const auto index = [&](int i, int j) { return i * col + j; };
    static const auto valid = [&](int i, int j) {
      return i >= 0 && j >= 0 && i < row && j < col;
    };
    static const int offset_x[] = {0, 0, 1, -1};
    static const int offset_y[] = {1, -1, 0, 0};

    UnionFind uf;

    for (int i = cells.size() - 1; i >= 0; i--) {
      const int x = cells[i][0] - 1, y = cells[i][1] - 1, ind = index(x, y);
      grid[ind] = true;

      for (int k = 0; k < 4; k++) {
        int i = x + offset_x[k], j = y + offset_y[k];
        if (!valid(i, j) || !grid[index(i, j)]) continue;
        uf.join(ind, index(i, j));
      }

      if (x == 0) uf.join(ind, 20000);
      if (x == row - 1) uf.join(ind, 20001);
      if (uf.connected(20000, 20001)) return i;
    }

    return row * col;
  }
};
