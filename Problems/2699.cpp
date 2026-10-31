class Solution {
public:
    std::vector<std::vector<int>> modifiedGraphEdges(
        int n,
        std::vector<std::vector<int>>& edges,
        int source,
        int destination,
        int target)
    {
        std::vector<std::vector<pair<int, int>>> adj(n);

        for (const auto& [idx, edge]: std::views::enumerate(edges)) {
            adj[edge[0]].emplace_back(edge[1], idx);
            adj[edge[1]].emplace_back(edge[0], idx);
        }

        std::vector<long long> distance(n);
        using State = std::tuple<long long, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        const auto dijkstra = [&](int start) {
            std::ranges::fill(distance, std::numeric_limits<long long>::max());
            distance[start] = 0;
            pq.emplace(0, start);
            while (!std::empty(pq)) {
                const auto [cost, node] = pq.top();
                pq.pop();
    
                if (cost != distance[node]) continue;
                
                for (const auto [child, idx]: adj[node]) {
                    if (edges[idx][2] == -1) continue;
                    const auto next_cost = cost + edges[idx][2];
                    if (next_cost >= distance[child]) continue;
                    distance[child] = next_cost;
                    pq.emplace(next_cost, child);
                }
            }
        };

        const auto block = [](auto &edges) {
            for (auto &edge: edges) {
                if (edge[2] != -1) continue;
                edge[2] = 2'000'000'000;
            }
            return edges;
        };

        dijkstra(source);
        if (distance[destination] < target) return {};
        if (distance[destination] == target) return block(edges);

        for (auto& edge: edges) {
            if (edge[2] != -1) continue;

            edge[2] = 1;
            dijkstra(source);

            if (distance[destination] <= target) {
                edge[2] += target - distance[destination];
                return block(edges);
            }
        }

        return {};
    }
};
