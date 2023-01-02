class UnionFind {
  vector<int> root, rank;

public:
  UnionFind(int n) : root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

  int find(int x) {
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
  }

  void join(int x, int y) {
    x = find(x), y = find(y);

    if (x != y) {
      if (rank[x] > rank[y]) swap(x, y);
      root[y] = x;
      rank[x] += x == y;
    }
  }
};

class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    UnionFind uf(s.size());
    vector<vector<char>> vs(s.size());

    for (auto &p : pairs) uf.join(p[0], p[1]);

    for (int i = 0; i < s.size(); i++) vs[uf.find(i)].push_back(s[i]);

    for (auto &s : vs) sort(s.rbegin(), s.rend());

    for (int i = 0; i < s.size(); i++) {
      int index = uf.find(i);
      s[i] = vs[index].back();
      vs[index].pop_back();
    }
    return s;
  }
};
