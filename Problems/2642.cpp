class Graph {
    typedef tuple<int, int> Edge;
    vector<vector<Edge>> adj;

  public:
    Graph(int n, const vector<vector<int>> &edges) : adj(n) {
        for (const auto &edge : edges)
            addEdge(edge);
    }

    void addEdge(const vector<int> edge) { adj[edge[0]].push_back({edge[2], edge[1]}); }

    int shortestPath(int node1, int node2) const {
        if (node1 == node2) return 0;
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        static int seen[101];
        memset(seen, 0x00, sizeof(seen));
        for (const Edge edge : adj[node1])
            pq.push(edge);
        while (!pq.empty()) {
            while (!pq.empty() && seen[get<1>(pq.top())])
                pq.pop();
            if (pq.empty()) break;
            const auto [w, n] = pq.top();
            pq.pop();
            if (n == node2) return w;
            seen[n] = true;
            for (const auto [w2, n2] : adj[n]) {
                if (!seen[n2]) pq.push({w + w2, n2});
            }
        }
        return -1;
    }
};
