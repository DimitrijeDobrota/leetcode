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

class Solution {
  typedef array<int, 3> edge;
  typedef vector<int> point;

  int distance(const point &p1, const point &p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    auto cmp = [](const edge &a, const edge &b) { return a[2] > b[2]; };
    priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
    UnionFind uf(points.size());

    for (int i = 0; i < points.size(); i++)
      for (int j = i + 1; j < points.size(); j++)
        pq.push({i, j, distance(points[i], points[j])});

    int res = 0;
    while (uf.count() != 1) {
      auto [s, d, w] = pq.top();
      pq.pop();
      if (uf.connected(s, d)) continue;
      uf.join(s, d);
      res += w;
    }
    return res;
  }
};
