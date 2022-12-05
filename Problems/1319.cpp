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
      rank[y] += rank[x];
    }
  }

  int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += root[i] == i;
    return cnt;
  }
};

class Solution {
public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    int count = 0;
    UnionFind uf(n);
    for (auto &edge : connections) {
      if (uf.find(edge[0]) == uf.find(edge[1]))
        count++;
      else
        uf.join(edge[0], edge[1]);
    }
    return count < uf.count() - 1 ? -1 : uf.count() - 1;
  }
};
