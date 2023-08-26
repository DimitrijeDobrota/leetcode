class UnionFind {
    vector<int> root, rank;

  public:
    UnionFind(int n) : root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        while (x != root[x])
            x = root[x] = root[root[x]];
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

class Solution {
  public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        UnionFind uf(n);
        for (auto &p : edges)
            uf.join(p[0], p[1]);

        return uf.find(source) == uf.find(destination);
    }
};
