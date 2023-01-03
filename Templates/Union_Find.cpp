class UnionFind {
  int n;
  vector<int> root, rank;

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
      rank[y] += 1;
      n--;
    }
  }

  int count() { return n; }
  bool connected(int x, int y) { return find(x) == find(y); }
};
