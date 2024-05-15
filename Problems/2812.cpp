class Solution {
  public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        static int offset[] = {-1, 0, 1, 0, -1};
        const int n = size(grid);

        using qtype_t = tuple<int, int>;
        queue<qtype_t> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                q.emplace(i, j);
            }
        }

        for (int lvl = 2; !q.empty(); lvl++) {
            for (int k = q.size(); k > 0; k--) {
                const auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    const int x = a + offset[k + 1];
                    const int y = b + offset[k];

                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (grid[x][y]) continue;

                    grid[x][y] = lvl;
                    q.emplace(x, y);
                }
            }
        }

        using pqtype_t = tuple<int, int, int>;
        priority_queue<pqtype_t> pq;

        int res = grid[0][0];

        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = -grid[0][0];
        while (!pq.empty()) {
            const auto [v, a, b] = pq.top();
            pq.pop();

            res = min(res, -grid[a][b]);
            if (a == n - 1 && b == n - 1) return res - 1;

            for (int k = 0; k < 4; k++) {
                const int x = a + offset[k + 1];
                const int y = b + offset[k];

                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (grid[x][y] < 0) continue;

                pq.emplace(grid[x][y], x, y);
                grid[x][y] = -grid[x][y];
            }
        }

        return 0;
    }
};
