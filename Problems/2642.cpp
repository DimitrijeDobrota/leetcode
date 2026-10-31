class Graph {
    std::vector<std::vector<std::pair<int, int>>> m_adj;

public:
    Graph(int n, vector<vector<int>>& edges)
        : m_adj(n)
    {
        for (const auto& edge: edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(const vector<int>& edge) {
        m_adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) const {
        using State = std::tuple<long long, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        static constexpr auto inf = std::numeric_limits<long long>::max();
        std::vector<long long> distance(std::size(m_adj), inf);

        distance[node1] = 0;
        pq.emplace(0, node1);
        while (!std::empty(pq)) {
            const auto [cost, node] = pq.top();
            pq.pop();

            if (cost != distance[node]) continue;
            if (node == node2) return cost;

            for (const auto [child, weight]: m_adj[node]) {
                const auto new_cost = cost + weight;
                if (new_cost >= distance[child]) continue;
                distance[child] = new_cost;
                pq.emplace(new_cost, child);
            }
        }

        return -1;
     
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

 class Graph {
    static constexpr auto inf = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> cost;

public:
    Graph(int n, vector<vector<int>>& edges)
        : cost(n, std::vector(n, inf))
    {
        for (const auto i : std::views::iota(0, n)) {
            cost[i][i] = 0;
        }

        for (const auto edge: edges) {
            cost[edge[0]][edge[1]] = edge[2];
        }

        for (const auto k: std::views::iota(0, n)) {
            for (const auto i: std::views::iota(0, n)) {
                for (const auto j: std::views::iota(0, n)) {
                    if (cost[i][k] == inf || cost[k][j] == inf) continue;
                    cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    void addEdge(const vector<int>& edge) {
        const int u = edge[0];
        const int v = edge[1];
        const int weight = edge[2];
    
        if (weight >= cost[u][v]) return;
    
        for (const auto i : std::views::iota(0UZ, std::size(cost))) {
            for (const auto j : std::views::iota(0UZ, std::size(cost))) {
                if (cost[i][u] == inf || cost[v][j] == inf) continue;
                cost[i][j] = std::min(cost[i][j], cost[i][u] + weight + cost[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) const {
        return cost[node1][node2] != inf ? cost[node1][node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */