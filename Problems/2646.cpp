class Solution {
  public:
    int minimumTotalPrice(int n, std::vector<std::vector<int>> &edges, std::vector<int> &price,
                          std::vector<std::vector<int>> &trips) const {
        std::vector<std::vector<int>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        std::vector<int> depth(n);
        std::vector<int> small(n);
        std::vector<int> big(n);

        const auto get_lca = [&](int u, int v) {
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

        {
            std::vector<std::tuple<int, int, int>> stack;
            stack.reserve(n);
            stack.emplace_back(0, 0, 0);
            while (!std::empty(stack)) {
                const auto [root, parent, crnt] = stack.back();
                const auto is_odd = crnt % 2;
                stack.pop_back();

                depth[root] = crnt;
                small[root] = parent;
                if (depth[parent] - depth[big[parent]] == depth[big[parent]] - depth[big[big[parent]]]) {
                    big[root] = big[big[parent]];
                } else {
                    big[root] = parent;
                }

                for (const auto child : adj[root]) {
                    if (child == parent) continue;
                    stack.emplace_back(child, root, crnt + 1);
                }
            }
        }

        std::vector<int> visits(n);
        for (const auto trip : trips) {
            const auto lca = get_lca(trip[0], trip[1]);
            if (lca != 0) visits[small[lca]]--;
            visits[trip[0]]++;
            visits[trip[1]]++;
            visits[lca]--;
        }

        std::vector<int> full(n, 0);
        std::vector<int> half(n, 0);
        {
            std::vector<std::tuple<int, int>> stack;
            stack.reserve(n);
            stack.emplace_back(0, 0);
            while (!std::empty(stack)) {
                auto [root, parent] = stack.back();
                stack.pop_back();

                if (root >= 0) {
                    stack.emplace_back(-root - 1, parent);
                    for (const auto child : adj[root]) {
                        if (child == parent) continue;
                        stack.emplace_back(child, root);
                    }
                    continue;
                }
                root = -root - 1;

                for (const auto child : adj[root]) {
                    if (child == parent) continue;
                    visits[root] += visits[child];
                    full[root] += std::min(full[child], half[child]);
                    half[root] += full[child];
                }

                full[root] += visits[root] * price[root];
                half[root] += visits[root] * (price[root] / 2);
            }
        }
        return std::min(full[0], half[0]);
    }
};
