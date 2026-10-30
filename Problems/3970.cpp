class Solution {
  public:
    long long shortestPath(int n, const std::vector<std::vector<int>> &edges, std::string_view labels,
                           int k) const {
        std::vector<std::vector<std::pair<int, int>>> adj(n);

        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        const long long inf = std::numeric_limits<long long>::max();
        std::vector<std::vector<long long>> dist(n, std::vector<long long>(k + 1, inf));

        using State = std::tuple<long long, int, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        dist[0][1] = 0;
        pq.emplace(0, 0, 1);
        while (!pq.empty()) {
            const auto [cost, node, count] = pq.top();
            pq.pop();

            if (cost != dist[node][count]) continue;
            if (node == n - 1) return cost;

            for (const auto &[child, weight] : adj[node]) {
                const int nextCount = labels[node] == labels[child] ? count + 1 : 1;
                if (nextCount > k) continue;

                const long long nextCost = cost + weight;
                if (nextCost >= dist[child][nextCount]) continue;

                dist[child][nextCount] = nextCost;
                pq.emplace(nextCost, child, nextCount);
            }
        }

        return -1;
    }
};
