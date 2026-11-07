class Solution {
  public:
    vector<int> minOperationsQueries(std::size_t n, const std::vector<std::vector<int>> &edges,
                                     const std::vector<std::vector<int>> &queries) {
        const auto levels = std::bit_width(n);

        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        std::vector<std::vector<int>> jump(levels, std::vector(n, 0));
        std::vector<std::array<int, 27>> count(n);
        std::vector<int> out_time(n);
        std::vector<int> in_time(n);
        std::size_t time = 0;

        std::vector<std::tuple<int, int>> stack;
        stack.reserve(n);
        stack.emplace_back(0, 0);
        while (!std::empty(stack)) {
            auto [root, parent] = stack.back();
            stack.pop_back();

            if (root < 0) {
                root = -root - 1;
                out_time[root] = time++;
                continue;
            }

            in_time[root] = time++;
            jump[0][root] = parent;
            for (const auto level : std::views::iota(1, levels)) {
                jump[level][root] = jump[level - 1][jump[level - 1][root]];
            }

            stack.emplace_back(-root - 1, parent);
            for (const auto [child, weight] : adj[root]) {
                if (child == parent) continue;
                stack.emplace_back(child, root);
                count[child] = count[root];
                count[child][weight]++;
            }
        }

        const auto is_ancestor = [&](int u, int v) {
            return in_time[u] <= in_time[v] && out_time[u] >= out_time[v];
        };

        const auto get_lca = [&](int u, int v) {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;

            for (const auto level : std::views::iota(0, levels) | std::views::reverse) {
                if (!is_ancestor(jump[level][u], v)) {
                    u = jump[level][u];
                }
            }
            return jump[0][u];
        };

        std::vector<int> result(std::size(queries));
        for (const auto [idx, query] : std::views::enumerate(queries)) {
            const auto u = query[0];
            const auto v = query[1];
            const auto w = get_lca(u, v);

            int max = 0;
            int total = 0;
            for (const auto i : std::views::iota(0, 27)) {
                const auto cnt = count[u][i] + count[v][i] - 2 * count[w][i];
                max = std::max(max, cnt);
                total += cnt;
            }

            result[idx] = total - max;
        }

        return result;
    }
};
