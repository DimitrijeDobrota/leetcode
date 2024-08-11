class Solution {
    bool isDisconected(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        bool seen = false;

        static int visit[31][31];
        memset(visit, 0x00, sizeof(visit));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j] || visit[i][j]) continue;
                if (seen) return true;
                seen = true;

                q.emplace(i, j);
                while (!q.empty()) {
                    const auto [a, b] = q.front();
                    q.pop();

                    static const int dir[] = {-1, 0, 1, 0, -1};
                    for (int k = 0; k < 4; k++) {
                        const int x = a + dir[k];
                        const int y = b + dir[k + 1];

                        if (x < 0 || y < 0 || x >= n || y >= m) continue;
                        if (!grid[x][y] || visit[x][y]) continue;
                        q.emplace(x, y);
                        visit[x][y] = 1;
                    }
                }
            }
        }

        return !seen;
    }

  public:
    int minDays(vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);

        if (isDisconected(grid)) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;

                grid[i][j] = 0;
                if (isDisconected(grid)) return 1;
                grid[i][j] = 1;
            }
        }

        return 2;
    }
};
