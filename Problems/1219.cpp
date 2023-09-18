class Solution {
    int n, m;
    bool valid(const int x, const int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    int dfs(vector<vector<int>> &grid, const int x, const int y) {
        static const int dir[] = {1, 0, -1, 0, 1};
        int res = 0;

        grid[x][y] = -grid[x][y];
        for (int k = 0; k < 4; k++) {
            const int i = x + dir[k + 1];
            const int j = y + dir[k];
            if (!valid(i, j) || grid[i][j] <= 0) continue;
            res = max(res, dfs(grid, i, j));
        }
        grid[x][y] = -grid[x][y];
        return grid[x][y] + res;
    }

  public:
    int getMaximumGold(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                res = max(res, dfs(grid, i, j));
        }
        return res;
    }
};
