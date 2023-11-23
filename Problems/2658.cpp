class Solution {
  public:
    int findMaxFish(vector<vector<int>> &grid) const {
        static const int offset[] = {1, 0, -1, 0, 1};
        const int n = grid.size(), m = grid[0].size();
        const auto valid = [n, m](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;
                int count = grid[i][j];
                grid[i][j] = 0;

                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    const auto [a, b] = q.front();
                    for (int k = 0; k < 4; k++) {
                        const int x = a + offset[k];
                        const int y = b + offset[k + 1];
                        if (!valid(x, y)) continue;
                        if (!grid[x][y]) continue;
                        count += grid[x][y];
                        grid[x][y] = 0;
                        q.push({x, y});
                    }
                    q.pop();
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
