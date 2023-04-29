class UnionFind {
  int n, cnt = n;
  vector<int> root, size;

public:
  UnionFind(int n) : n(n), root(n), size(n, 1) {
    iota(root.begin(), root.end(), 0);
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
      cnt--;
    }
  }

  int count() { return cnt; }
  bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edges,
                                         vector<vector<int>> &queries) {
    vector<bool> res(queries.size());
    UnionFind uf(n);

    for (int i = 0; i < queries.size(); ++i) queries[i].push_back(i);

    const auto cmp = [](auto &a, auto &b) { return a[2] < b[2]; };
    sort(begin(queries), end(queries), cmp);
    sort(begin(edges), end(edges), cmp);

    int i = 0;
    for (auto &q : queries) {
      for (; i < edges.size() && edges[i][2] < q[2]; i++)
        uf.join(edges[i][0], edges[i][1]);
      res[q[3]] = uf.connected(q[0], q[1]);
    }
    return res;
  }
};
