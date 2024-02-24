class UnionFind {
    int n, cnt = n;
    mutable vector<int> root;
    vector<int> size;

  public:
    UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }
    UnionFind(const UnionFind &uf) : n(uf.n), cnt(uf.cnt), root(uf.root), size(uf.size) {}

    int find(int x) const {
        while (x != root[x]) {
            x = root[x] = root[root[x]];
        }
        return x;
    }

    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (size[x] > size[y]) swap(x, y);
        root[x] = y;
        size[y] += size[x];
        cnt--;
    }

    void reset(int x) {
        root[x] = x;
        size[x] = 0;
    }

    int count() const { return cnt; }
    bool connected(int x, int y) const { return find(x) == find(y); }
};
