class Solution {
  public:
    std::vector<int> findSubtreeSizes(const std::vector<int> &parents, const std::string &s) const {
        const auto n = std::size(parents);
        std::vector<std::vector<int>> adj(n);

        for (const auto [child, parent] : parents | std::views::enumerate | std::views::drop(1)) {
            adj[parent].emplace_back(child);
        }

        std::array<int, 26> nearest;
        std::ranges::fill(nearest, -1);

        std::vector<std::tuple<int, int, bool>> stack;
        std::vector<int> result(n, 1);

        stack.emplace_back(0, -1, false);
        while (!std::empty(stack)) {
            auto [node, previous, exists] = stack.back();
            stack.pop_back();

            auto &ancestor = nearest[s[node] - 'a'];
            if (exists) {
                ancestor = previous;
                const auto parent = previous != -1 ? previous : parents[node];
                if (parent != -1) {
                    result[parent] += result[node];
                }
            } else {
                stack.emplace_back(node, ancestor, true);
                ancestor = node;

                for (const auto child : adj[node]) {
                    stack.emplace_back(child, -1, false);
                }
            }
        }

        return result;
    }
};
