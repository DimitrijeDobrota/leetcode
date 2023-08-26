class Solution {
    bool valid(int n, int x, int y) { return x >= 0 && y >= 0 && x < n && y < n; }

    double dp[25][25][101];

  public:
    double knightProbability(int n, int k, int row, int column) {
        static const int offset_x[] = {-2, -2, -1, 1, 2, 2, 1, -1};
        static const int offset_y[] = {-1, 1, 2, 2, 1, -1, -2, -2};

        if (!k) return 1;
        if (dp[row][column][k]) return dp[row][column][k];

        double res = 0;
        for (int i = 0; i < 8; i++) {
            int x = row + offset_x[i];
            int y = column + offset_y[i];

            if (!valid(n, x, y)) continue;
            res += 0.125 * knightProbability(n, k - 1, x, y);
        };

        return dp[row][column][k] = res;
    }
};
