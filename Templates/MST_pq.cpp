// Kruskal's Algorithm
// Require UnionFind

int MST(int n, priority_queue<edge> &pq) {
    int weight = 0;

    UnionFind uf(n);
    while (!pq.empty() && uf.count() != 1) {
        const auto &e = pq.top();
        pq.pop();
        if (uf.connected(e[0], e[1])) continue;
        uf.join(e[0], e[1]);
        weight += e[2];
    }

    return uf.count() == 1 ? weight : 1e9 + 7;
}
