class UnionFind {
  vector<int> root, rank;
  int n;

public:
  UnionFind(int n) : n(n), root(n), rank(n, 1) {
    iota(root.begin(), root.end(), 0);
  }

  int find(int x) {
    while (x != root[x]) x = root[x] = root[root[x]];
    return x;
  }

  void join(int x, int y) {
    x = find(x), y = find(y);

    if (x != y) {
      if (rank[x] > rank[y]) swap(x, y);

      root[x] = y;
      rank[y] += rank[x];
    }
  }

  int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += root[i] == i;
    return cnt;
  }

  void set_invalid(int x) { root[x] = -1; }
};

class Solution {
  int n;

  int get_base_index(int x, int y) { return (n * x + y) * 2; }

  bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

  int get_start_offset(char c, int k) {
    if (c == '/')
      return (k % 2 == 0) ? 1 : 0;
    else
      return (k == 0 || k == 3) ? 1 : 0;
  }

  int get_index(char c, int k, int x, int y, bool dest) {
    int offset = get_start_offset(c, k);
    if (dest) offset = !offset;
    return get_base_index(x, y) + (c != ' ') * offset;
  }

public:
  int regionsBySlashes(vector<string> &grid) {
    n = grid.size();
    UnionFind uf(2 * n * n);

    vector<pair<int, int>> offset = {
        { 0,  1},
        { 0, -1},
        { 1,  0},
        {-1,  0}
    };
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        for (int k = 0; k < 4; k++) {
          int nx = x + offset[k].first, ny = y + offset[k].second;
          if (!valid(nx, ny)) continue;
          int index = get_index(grid[x][y], k, x, y, 0);
          int nindex = get_index(grid[nx][ny], k, nx, ny, 1);
          uf.join(index, nindex);
        }
        if (grid[x][y] == ' ') uf.set(get_base_index(x, y) + 1);
      }
    }

    return uf.count();
  }
};
