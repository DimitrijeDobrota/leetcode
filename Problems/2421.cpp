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
};

class Solution {
public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    int n = vals.size();
    map<int, vector<int>> valuesToNodes;
    vector<vector<int>> adj(n);
    UnionFind uf(n);

    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; i++) valuesToNodes[vals[i]].push_back(i);

    int goodPaths = 0;
    for (auto &[value, nodes] : valuesToNodes) {
      for (int node : nodes) {
        for (int neighbor : adj[node]) {
          if (vals[node] >= vals[neighbor]) { uf.join(node, neighbor); }
        }
      }
      unordered_map<int, int> group;
      for (int u : nodes) group[uf.find(u)]++;
      for (auto &[_, size] : group) goodPaths += (size * (size + 1) / 2);
    }
    return goodPaths;
  }
};
