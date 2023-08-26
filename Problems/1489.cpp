class UnionFind {
    int n;
    vector<int> root, rank;

  public:
    UnionFind(int n) : n(n), root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

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
            rank[y] += 1;
            n--;
        }
    }

    int count() { return n; }
    bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
    typedef vector<int> edge;

    int get_mst(int n, const vector<edge> &edges, int blockedge, int pre_edge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if (pre_edge != -1) {
            weight += edges[pre_edge][2];
            uf.join(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size() && uf.count() != 1; ++i) {
        }
        if (i == blockedge) continue;
        const auto &e = edges[i];
        if (uf.connected(e[0], e[1])) continue;
        uf.join(e[0], e[1]);
        weight += e[2];
    }

    return uf.count() == 1 ? weight : 1e9 + 7;
} public : vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<edge> &edges) {
    for (int i = 0; i < edges.size(); i++)
        edges[i].push_back(i);
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) { return a[2] < b[2]; });
    int origin_mst = get_mst(n, edges, -1);

    vector<int> critical, non_critical;
    for (int i = 0; i < edges.size(); i++) {
        if (origin_mst < get_mst(n, edges, i))
            critical.push_back(edges[i][3]);
        else if (origin_mst == get_mst(n, edges, -1, i))
            non_critical.push_back(edges[i][3]);
    }
    return {critical, non_critical};
}
}
;
