class UnionFind {
  vector<int> root, rank;

public:
  UnionFind(int n) : root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

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
};

struct edge {
  int p1, p2;
  int cost;
  edge(int p1 = -1, int p2 = -1, int cost = INT_MAX)
      : p1(p1), p2(p2), cost(cost) {}
  bool operator()(const edge &e1, const edge &e2) { return e1.cost > e2.cost; }
};

class Solution {
  int distance(vector<int> &p1, vector<int> &p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    UnionFind uf(points.size() * (points.size() + 1) / 2);
    priority_queue<edge, vector<edge>, edge> pq;

    for (int i = 0; i < points.size(); i++)
      for (int j = i + 1; j < points.size(); j++)
        pq.push(edge(i, j, distance(points[i], points[j])));

    int num = 1, res = 0;
    while (num < points.size()) {
      edge e = pq.top();
      pq.pop();
      if (uf.find(e.p1) != uf.find(e.p2)) {
        res += e.cost;
        uf.join(e.p1, e.p2);
        num++;
      }
    }
    return res;
  }
};
