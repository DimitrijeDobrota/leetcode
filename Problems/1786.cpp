class Solution {
public:
    int countRestrictedPaths(int n, const std::vector<std::vector<int>>& edges) const {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
            adj[edge[1] - 1].emplace_back(edge[0] - 1, edge[2]);
        }

        using State = std::tuple<long long, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;
        std::vector<long long> distance(n, std::numeric_limits<long long>::max());
        std::vector<int> ways(n, 0);

        ways[n - 1] = 1;
        distance[n - 1] = 0;
        pq.emplace(0, n - 1);
        while (!std::empty(pq)) {
            const auto [cost, node] = pq.top();
            pq.pop();

            if (cost != distance[node]) continue;

            for (const auto [child, weight]: adj[node]) {
                if (distance[child] < cost) {
                    ways[node] = (ways[node] + ways[child]) % (int)(1e9 + 7);
                }

                const auto new_cost = cost + weight;
                if (new_cost >= distance[child]) continue;
                distance[child] = new_cost;
                pq.emplace(new_cost, child);
            }
        }

        return ways[0];
    }
};