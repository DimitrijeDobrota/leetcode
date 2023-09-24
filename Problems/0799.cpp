class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        static double dp[102][102];
        memset(dp, 0x00, sizeof(dp));

        dp[0][0] = (double)poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double split = (dp[i][j] - 1.0) / 2.0;
                if (split > 0) {
                    dp[i + 1][j] += split;
                    dp[i + 1][j + 1] += split;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};
