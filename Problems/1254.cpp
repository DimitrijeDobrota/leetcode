class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) const{
        const std::size_t n = std::size(grid);
        const std::size_t m = std::size(grid[0]);

        const auto in_range = [&](std::size_t x, std::size_t y) {
            return x < n && y < m;
        };

        const auto visit = [&](std::size_t x, std::size_t y) {
            queue<pair<std::size_t, std::size_t>> q;
            q.emplace(x, y);
            grid[x][y] = 1;

            while (!q.empty()) {
                const auto [x, y] = q.front();
                q.pop();

                static constexpr std::array dir = { -1, 0, 1, 0, -1};
                for (std::size_t o = 1; o < std::size(dir); o++) {
                    const std::size_t i = x + dir[o - 1];
                    const std::size_t j = y + dir[o];
                    if (!in_range(i, j) || grid[i][j] == 1) continue;
                    q.emplace(i, j);
                    grid[i][j] = 1;
                }
            }
        };

        for (std::size_t i = 0; i < n; i++) {
            if (grid[i][0] == 0) visit(i, 0);
            if (grid[i][m - 1] == 0) visit(i, m - 1);
        }

        for (std::size_t j = 0; j < m; j++) {
            if (grid[0][j] == 0) visit(0, j);
            if (grid[n - 1][j] == 0) visit(n - 1, j);
        }

        int result = 0;
        for (std::size_t i = 1; i < n - 1; i++) {
            for (std::size_t j = 1; j < m - 1; j++) {
                if (grid[i][j] == 1) continue;
                visit(i, j);
                result++;
            }
        }
        return result;
    }
};