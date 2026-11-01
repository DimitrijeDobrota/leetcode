class Solution {
  public:
    vector<int> assignEdgeWeights(const std::vector<std::vector<int>> &edges,
                                  const std::vector<std::vector<int>> &queries) {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
        }

        std::vector<int> depth(n);
        std::vector<int> small(n);
        std::vector<int> big(n);

        std::vector<tuple<int, int, int>> stack;
        stack.reserve(n);
        stack.emplace_back(0, 0, 0);
        while (!std::empty(stack)) {
            const auto [root, parent, cdepth] = stack.back();
            stack.pop_back();

            depth[root] = cdepth;
            small[root] = parent;
            if (depth[parent] - depth[big[parent]] == depth[big[parent]] - depth[big[big[parent]]]) {
                big[root] = big[big[parent]];
            } else {
                big[root] = parent;
            }

            for (const auto child : adj[root]) {
                if (child == parent) continue;
                stack.emplace_back(child, root, cdepth + 1);
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

        const auto exp = [](int n) {
            if (n <= 1) return n;
            static constexpr int mod = 1e9 + 7;
            long long multiplier = 2;
            long long result = 1;

            n--;
            while (n > 0) {
                if (n & 1) {
                    result = (result * multiplier) % mod;
                }
                multiplier = (multiplier * multiplier) % mod;
                n >>= 1;
            }
            return static_cast<int>(result);
        };

        std::vector<int> result(std::size(queries));
        for (const auto &[idx, query] : std::views::enumerate(queries)) {
            const auto u = query[0] - 1;
            const auto v = query[1] - 1;
            const auto len = depth[u] + depth[v] - 2 * depth[find_lca(u, v)];
            result[idx] = exp(len);
        }
        return result;
    }
};
