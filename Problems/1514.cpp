class Solution {
public:
    double maxProbability(
        int n,
        const std::vector<std::vector<int>>& edges,
        const std::vector<double>& succProb,
        int start_node,
        int end_node)
    {
        std::vector<std::vector<std::pair<int, double>>> adj(n);
        for (const auto& [edge, prob]: std::views::zip(edges, succProb)) {
            adj[edge[0]].emplace_back(edge[1], prob);
            adj[edge[1]].emplace_back(edge[0], prob);
        }

        std::vector<double> distance(n, 0.0);
        std::priority_queue<std::tuple<double, int>> pq;

        distance[start_node] = 1.0;
        pq.emplace(1.0, start_node);
        while (!std::empty(pq)) {
            const auto [cost, node] = pq.top();
            pq.pop();

            if (cost != distance[node]) continue;
            if (node == end_node) return cost;

            for (const auto [child, weight]: adj[node]) {
                const auto new_cost = cost * weight;
                if (new_cost <= distance[child]) continue;
                distance[child] = new_cost;
                pq.emplace(new_cost, child);
            }
        }

        return 0;
    }
};