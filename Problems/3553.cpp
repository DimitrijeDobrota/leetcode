class Solution {
  public:
    vector<int> minimumWeight(const std::vector<std::vector<int>> &edges,
                              const std::vector<std::vector<int>> &queries) {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        std::vector<int> distance(n);
        std::vector<int> depth(n);
        std::vector<int> small(n);
        std::vector<int> big(n);

        std::vector<std::tuple<int, int, int, int>> stack;
        stack.reserve(n);
        stack.emplace_back(0, 0, 0, 0);
        while (!std::empty(stack)) {
            const auto [root, parent, cdepth, dist] = stack.back();
            stack.pop_back();

            distance[root] = dist;
            depth[root] = cdepth;
            small[root] = parent;
            if (depth[parent] - depth[big[parent]] == depth[big[parent]] - depth[big[big[parent]]]) {
                big[root] = big[big[parent]];
            } else {
                big[root] = parent;
            }

            for (const auto [child, weight] : adj[root]) {
                if (child == parent) continue;
                stack.emplace_back(child, root, cdepth + 1, dist + weight);
            }
        }

        const auto find_lca = [&](int u, int v) {
            if (depth[u] < depth[v]) std::swap(u, v);
            while (depth[u] != depth[v]) {
                if (depth[big[u]] >= depth[v]) {
                    u = big[u];
                } else {
                    u = small[u];
                }
            }

            while (u != v) {
                if (big[u] != big[v]) {
                    u = big[u];
                    v = big[v];
                } else {
                    u = small[u];
                    v = small[v];
                }
            }
            return u;
        };

        const auto length = [&](int u, int v) {
            return distance[u] + distance[v] - 2 * distance[find_lca(u, v)];
        };

        std::vector<int> result(std::size(queries));
        for (const auto &[idx, query] : std::views::enumerate(queries)) {
            result[idx] =
                length(query[0], query[1]) + length(query[0], query[2]) + length(query[1], query[2]);
            result[idx] /= 2;
        }
        return result;
    }
};
