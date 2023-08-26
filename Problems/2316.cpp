class UnionFind {
    int n, cnt = n;
    vector<int> root, size;

  public:
    UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        while (x != root[x])
            x = root[x] = root[root[x]];
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

    long long count_unreachable() {
        long long res = 0;

        for (int i = 0; i < n; i++)
            if (root[i] == i) res += (long long)size[i] * (n - size[i]);

        return res / 2;
    }
};

class Solution {
  public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        for (auto &e : edges)
            uf.join(e[0], e[1]);
        return uf.count_unreachable();
    }
};
