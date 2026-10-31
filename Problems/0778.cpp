class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) const {
        using State = std::tuple<int, std::size_t, std::size_t>;
        std::priority_queue<State, std::vector<State>, std::greater<>> pq;

        const auto n = std::size(grid);
        const auto m = std::size(grid[0]);

        pq.emplace(grid[0][0], 0, 0);
        while (!std::empty(pq)) {
            const auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return time;

            static constexpr std::array offset = {-1, 0, 1, 0, -1};
            for (const auto idx: std::views::iota(1UZ, std::size(offset))) {
                const auto i = x + offset[idx - 1];
                const auto j = y + offset[idx];

                if (i >= n || j >= m) continue;
                if (grid[i][j] < 0) continue;

                pq.emplace(std::max(time, grid[i][j]), i, j);
                grid[i][j] = -1;
            }
        }

        return -1;
 
    }
};