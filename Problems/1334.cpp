class Solution {
public:
    int findTheCity(int n, const vector<vector<int>>& edges, int threshold) const {
        std::vector<std::vector<pair<int, int>>> adj(n);

        for (const auto& edge: edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        std::vector<long long> dist(n);
        using State = std::tuple<long long, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        const auto dijkstra = [threshold, &adj, &dist, &pq](int start) {
            std::ranges::fill(dist, std::numeric_limits<long long>::max());
            dist[start] = 0;
            pq.emplace(0, start);
            while (!std::empty(pq)) {
                const auto [cost, node] = pq.top();
                pq.pop();
    
                if (cost != dist[node]) continue;
                
                for (const auto [child, weight]: adj[node]) {
                    const auto next_cost = cost + weight;
                    if (next_cost > threshold) continue;
                    if (next_cost >= dist[child]) continue;
                    dist[child] = next_cost;
                    pq.emplace(next_cost, child);
                }
            }
            return std::ranges::count_if(dist, [threshold](auto value) {
                return value <= threshold;
            });
        };

        int result = -1;
        auto min = std::numeric_limits<int>::max();
        for (const auto crnt: std::views::iota(0, n)) {
            const auto num = dijkstra(crnt);
            if (num > min) continue;
            result = crnt;
            min = num;
        }
        return result;
    }
};