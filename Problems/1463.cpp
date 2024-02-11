class Solution {
    static int dp[70][70][70];

    static int dfs(const vector<vector<int>> &grid, int r, int c1, int c2) {
        const int n = size(grid), m = size(grid[0]);

        if (r == n) return 0;
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int res = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                const int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 < 0 || nc1 >= m || nc2 < 0 || nc2 >= m) continue;
                res = max(res, dfs(grid, r + 1, nc1, nc2));
            }
        }

        const int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = res + cherries;
    }

  public:
    int cherryPickup(const vector<vector<int>> &grid) const {
        memset(dp, 0xFF, sizeof(dp));
        return dfs(grid, 0, 0, size(grid[0]) - 1);
    }
};

int Solution::dp[70][70][70];
