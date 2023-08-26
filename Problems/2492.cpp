class UnionFind {
    int n;
    vector<int> root, rank, res;

  public:
    UnionFind(int n) : n(n), root(n), rank(n, 1), res(n, INT_MAX) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        while (x != root[x])
            x = root[x] = root[root[x]];
        return x;
    }

    void join(int x, int y, int val) {
        x = find(x), y = find(y);
        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            res[y] = min(res[x], res[y]);
            root[x] = y;
            rank[y] += rank[x];
        }
        res[y] = min(val, res[y]);
    }

    int mini(int x) { return res[find(x)]; }
};

class Solution {
  public:
    int minScore(int n, vector<vector<int>> &roads) {
        UnionFind uf(n + 1);
        for (auto &r : roads)
            uf.join(r[0], r[1], r[2]);
        return uf.mini(n);
    }
};
