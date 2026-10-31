class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const auto n = std::size(heights);
        const auto m = std::size(heights[0]);

        static constexpr auto inf = std::numeric_limits<int>::max();
        std::vector<std::vector<int>> distance(n, std::vector(m, inf));
        using state = std::tuple<int, std::size_t, std::size_t>;
        std::priority_queue<state, std::vector<state>, std::greater<>> pq;

        distance[0][0] = 0;
        pq.emplace(0, 0, 0);
        while (!std::empty(pq)) {
            const auto [cost, i, j] = pq.top();
            pq.pop();

            if (cost != distance[i][j]) continue;
            if (i == n - 1 && j == m - 1) return cost;

            static constexpr std::array offset = { -1, 0, 1, 0, -1};
            for (const auto idx: std::views::iota(1UZ, std::size(offset))) {
                const auto x = i + offset[idx - 1];
                const auto y = j + offset[idx];
                if (x >= n || y >= m) continue;
                const auto new_cost = std::max(cost, std::abs(heights[i][j] - heights[x][y]));
                if (new_cost >= distance[x][y]) continue;
                distance[x][y] = new_cost;
                pq.emplace(new_cost, x, y);
            }
        }

        return 0; 
    }
};