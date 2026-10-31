class Solution {
public:
    int findCheapestPrice(int n, const std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& edge: flights) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        using State = std::tuple<long long, int, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        static constexpr auto inf = std::numeric_limits<long long>::max();
        std::vector<std::vector<long long>> distance(n, std::vector(k + 2, inf));

        distance[src][0] = 0;
        pq.emplace(0, 0, src);
        while (!std::empty(pq)) {
            const auto [cost, used, node] = pq.top();
            pq.pop();

            if (cost != distance[node][used]) continue;
            if (node == dst) return cost;
            if (used == k + 1) continue;

            for (const auto [child, weight]: adj[node]) {
                const auto new_cost = cost + weight;
                const auto next_used = used + 1;
                if (new_cost >= distance[child][next_used]) continue;
                distance[child][next_used] = new_cost;
                pq.emplace(new_cost, next_used, child);
            }
        }

        return -1;
     }
};
