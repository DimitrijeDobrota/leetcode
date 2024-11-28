class Solution {
  public:
    int minimumObstacles(vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);

        vector<vector<int>> d(n, vector(m, INT_MAX / 2));
        deque<pair<int, int>> dq = {{0, 0}};

        static const int offset[] = {-1, 0, 1, 0, -1};
        const auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };

        for (d[0][0] = 0; !dq.empty();) {
            const auto [a, b] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                const int x = a + offset[k + 1];
                const int y = b + offset[k];

                if (!valid(x, y) || d[x][y] != INT_MAX / 2) continue;
                if (d[a][b] + grid[x][y] >= d[x][y]) continue;

                d[x][y] = d[a][b] + grid[x][y];

                if (grid[x][y] == 1)
                    dq.emplace_back(x, y);
                else
                    dq.emplace_front(x, y);
            }
        }

        return d[n - 1][m - 1];
    }
};
