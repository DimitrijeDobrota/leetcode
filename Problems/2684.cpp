class Solution {
  public:
    int maxMoves(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        static int dp[1001];

        memset(dp, 0x00, sizeof(dp));
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0, prev; i < n; i++) {
                int crnt = 0;
                if (i > 0 && grid[i][j] < grid[i - 1][j + 1]) crnt = max(crnt, prev + 1);
                if (grid[i][j] < grid[i][j + 1]) crnt = max(crnt, dp[i] + 1);
                if (i < n - 1 && grid[i][j] < grid[i + 1][j + 1]) crnt = max(crnt, dp[i + 1] + 1);
                prev = dp[i];
                dp[i] = crnt;
            }
        }

        return *max_element(dp, dp + n);
    }
};
