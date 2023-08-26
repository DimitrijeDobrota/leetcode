// Kruskal's Algorithm
// Require UnionFind

int get_mst(int n, const vector<edge> &edges) {
    int weight = 0;

    UnionFind uf(n);
    for (int i = 0; i < edges.size() && uf.count() != 1; i++) {
        const auto &e = edges[i];
        if (uf.connected(e[0], e[1])) continue;
        uf.join(e[0], e[1]);
        weight += e[2];
    }

    return uf.count() == 1 ? weight : 1e9 + 7;
}
