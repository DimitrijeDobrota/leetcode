class Solution {
public:
    int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) const {
        std::vector<std::vector<pair<int, int>>> adj(n);
        for (const auto& edge: times) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
        }

        static constexpr auto inf = std::numeric_limits<int>::max();
        std::vector<int> distance(n, inf);
        using State = std::tuple<int, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        distance[k - 1] = 0;
        pq.emplace(0, k - 1);
        while (!pq.empty()) {
            const auto [cost, node] = pq.top();
            pq.pop();

            if (cost != distance[node]) continue;

            for (const auto [child, weight]: adj[node]) {
                const auto next_cost = cost + weight;
                if (next_cost >= distance[child]) continue;
                distance[child] = next_cost;
                pq.emplace(next_cost, child);
            }
        }
        
        const auto max = std::ranges::max(distance);
        return max != inf ? max : -1;
    }
};

class Solution {
public:
    int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) const {
        std::vector<std::vector<pair<int, int>>> adj(n);
        for (const auto& edge: times) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
        }

        static constexpr auto inf = std::numeric_limits<int>::max();
        std::vector<int> visited(n, false);
        std::vector<int> distance(n, inf);

        distance[k - 1] = 0;
        for (const auto iter: std::views::iota(0, n)) {
            int node = -1;

            for (const auto candid: std::views::iota(0, n)) {
                if (visited[candid]) continue;

                if (node == -1 || distance[candid] < distance[node]) {
                    node = candid;
                }
            }

            if (node == -1 || distance[node] == inf) return -1;

            visited[node] = true;
            for (const auto [child, weight]: adj[node]) {
                if (visited[child]) continue;

                const int nextCost = distance[node] + weight;
                if (nextCost >= distance[child]) continue;

                distance[child] = nextCost;
            }
        }
        
        return std::ranges::max(distance);
    }
};