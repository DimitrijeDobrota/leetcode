class Solution {
  public:
    vector<int> findMedian(std::size_t n, const std::vector<std::vector<int>> &edges,
                           const std::vector<std::vector<int>> &queries) const {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        const auto levels = std::bit_width(n);
        std::vector<std::vector<int>> jump(levels, std::vector(n, 0));
        std::vector<int> parent_dist(n);
        std::vector<int> out_time(n);
        std::vector<int> in_time(n);
        std::size_t time = 0;

        std::vector<long long> total(n);

        std::vector<std::tuple<int, int, long long>> stack;
        stack.reserve(n);
        stack.emplace_back(0, 0, 0);
        while (!stack.empty()) {
            auto [root, parent, dist] = stack.back();
            stack.pop_back();

            if (root < 0) {
                root = -root - 1;
                out_time[root] = time++;
                continue;
            }

            total[root] = dist;
            in_time[root] = time++;
            jump[0][root] = parent;
            for (const auto level : std::views::iota(1, levels)) {
                jump[level][root] = jump[level - 1][jump[level - 1][root]];
            }

            stack.emplace_back(-root - 1, parent, 0);
            for (const auto [child, weigth] : adj[root]) {
                if (child == parent) continue;
                stack.emplace_back(child, root, dist + weigth);
                parent_dist[child] = weigth;
            }
        }

        const auto is_ancestor = [&](int u, int v) {
            return in_time[u] <= in_time[v] && out_time[v] <= out_time[u];
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

            if (u == v) {
                result[idx] = u;
                continue;
            }

            const auto w = get_lca(u, v);
            const auto distance = total[u] + total[v] - 2 * total[w];

            int res;
            if (2 * (total[u] - total[w]) >= distance) {
                res = u;
                for (const auto level : std::views::iota(0, levels) | std::views::reverse) {
                    const auto next = jump[level][res];
                    if (2 * (total[u] - total[next]) < distance) res = next;
                }
                res = jump[0][res];
            } else {
                res = v;
                for (const auto level : std::views::iota(0, levels) | std::views::reverse) {
                    const auto next = jump[level][res];
                    if (2 * (total[v] - total[next]) <= distance) res = next;
                }
            }
            result[idx] = res;
        }
        return result;
    }
};
