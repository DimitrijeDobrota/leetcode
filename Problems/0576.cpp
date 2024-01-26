class Solution {
    static const int MOD = 1E9 + 7;
    static int dp[51][51][51];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int findPaths(const int m, const int n, const int moves, const int row, const int col) const {
        if (!moves) return 0;
        if (dp[moves][row][col] != -1) return dp[moves][row][col];
        int res = 0;

        static int offset[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            const int x = row + offset[k];
            const int y = col + offset[k + 1];
            if (x < 0 || y < 0 || x >= m || y >= n)
                res++;
            else
                res = (res + findPaths(m, n, moves - 1, x, y)) % MOD;
        }

        return dp[moves][row][col] = res;
    }
};

int Solution::dp[51][51][51];
