class UnionFind {
  int n, cnt = n;
  vector<int> root;

public:
  UnionFind(int n) : n(n), root(n) { iota(root.begin(), root.end(), 0); }

  int find(int x) {
    while (x != root[x]) x = root[x] = root[root[x]];
    return x;
  }

  void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      if (y > x) swap(x, y);
      root[x] = y;
    }
  }
};

class Solution {
public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionFind uf(126);

    for (int i = 0; i < s1.size(); i++) uf.join(s1[i], s2[i]);

    for (char &c : baseStr) c = uf.find(c);
    return baseStr;
  }
};
