class Solution {
  public:
    int minSideJumps(const vector<int> &obstacles) const {
        static unsigned dp[500002][3];
        const int n = size(obstacles);

        memset(dp, 0xF0, sizeof(dp));
        memset(dp[n - 1], 0x00, sizeof(dp[n]));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i + 1] == j + 1) continue;
                if (obstacles[i] == j + 1) continue;
                dp[i][j] = dp[i + 1][j];
            }

            dp[i][0] = min({dp[i][0], dp[i][1] + 1, dp[i][2] + 1});
            dp[i][1] = min({dp[i][1], dp[i][0] + 1, dp[i][2] + 1});
            dp[i][2] = min({dp[i][2], dp[i][0] + 1, dp[i][1] + 1});
        }

        return dp[0][1];
    }
};
