class Solution {
public:
    int countPaths(int n, const vector<vector<int>>& roads) const {
        std::vector<std::vector<pair<int, int>>> adj(n);
        for (const auto& edge: roads) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        static constexpr auto inf = std::numeric_limits<long long>::max();
        std::vector<long long> distance(n, inf);
        std::vector<int> ways(n, 0);
        using State = std::tuple<long long, int>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        ways[n - 1] = 1;
        distance[n - 1] = 0;
        pq.emplace(0, n - 1);
        while (!pq.empty()) {
            const auto [cost, node] = pq.top();
            pq.pop();

            if (cost != distance[node]) continue;
            if (node == 0) return ways[0];


            for (const auto [child, weight]: adj[node]) {
                const auto next_cost = cost + weight;
                if (next_cost < distance[child]) {
                    distance[child] = next_cost;
                    ways[child] = ways[node];
                    pq.emplace(next_cost, child);
                } else if (next_cost == distance[child]) {
                    ways[child] = (ways[child] + ways[node]) % (int)(1e9 + 7);
                }
            }
        }
        
        return -1;
    }
};