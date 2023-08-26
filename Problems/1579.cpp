class UnionFind {
    int n, cnt = n;
    vector<int> root, size;

  public:
    UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    UnionFind(const UnionFind &uf) : n(uf.n), cnt(uf.cnt), root(uf.root), size(uf.size) {}

    static int redundant;

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
        } else
            redundant++;
    }

    int count() { return cnt; }
    bool connected(int x, int y) { return find(x) == find(y); }
};

int UnionFind::redundant = 0;

class Solution {
  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &e) {
        UnionFind::redundant = 0;

        UnionFind a(n + 1);
        for (int i = 0; i < e.size(); i++)
            if (e[i][0] == 3) a.join(e[i][1], e[i][2]);

        UnionFind b = a;
        for (int i = 0; i < e.size(); i++)
            if (e[i][0] == 1)
                a.join(e[i][1], e[i][2]);
            else if (e[i][0] == 2)
                b.join(e[i][1], e[i][2]);

        // count must be 2, since 0 is not used
        return a.count() == 2 && b.count() == 2 ? UnionFind::redundant : -1;
    }
};
