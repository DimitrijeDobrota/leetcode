
class Solution {
  public:
    int countSubIslands(const vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        static constexpr const int offset_x[] = {0, 0, 1, -1};
        static constexpr const int offset_y[] = {1, -1, 0, 0};
        const int n = grid1.size(), m = grid1[0].size();
        const auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid2[i][j] || !grid1[i][j]) continue;
                grid2[i][j] = 0;
                queue<pair<int, int>> q({{i, j}});
                bool sub = true;
                while (!q.empty()) {
                    const auto [i, j] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        const int x = i + offset_x[k];
                        const int y = j + offset_y[k];
                        if (!valid(x, y) || !grid2[x][y]) continue;
                        if (!grid1[x][y]) sub = false;
                        grid2[x][y] = 0;
                        q.push({x, y});
                    }
                }
                res += sub;
            }
        }
        return res;
    }
};
