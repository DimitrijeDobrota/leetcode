// Top-down
class Solution {
    static int dp[501][501];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int paintWalls(const vector<int> &cost, const vector<int> &time, int crnt = 0, int total = 0) {
        if (total >= cost.size()) return 0;
        if (crnt == cost.size()) return 1e9;
        if (dp[crnt][total] != -1) return dp[crnt][total];

        const int paint = cost[crnt] + paintWalls(cost, time, crnt + 1, total + time[crnt] + 1);
        const int dont = paintWalls(cost, time, crnt + 1, total);
        return dp[crnt][total] = min(paint, dont);
    }
};

int Solution::dp[501][501];

// Bottom-up
class Solution {
  public:
    int paintWalls(const vector<int> &cost, const vector<int> &time) {
        static unsigned dp[501][501];
        memset(dp, 0x00, sizeof(dp));

        const int n = cost.size();
        for (int i = 1; i <= 500; i++)
            dp[n][i] = 1e9;

        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                const int paint = cost[i] + dp[i + 1][max(0, remain - time[i] - 1)];
                const int dont = dp[i + 1][remain];
                dp[i][remain] = min(paint, dont);
            }
        }

        return dp[0][n];
    }
};

// Space optimized Bottom-up
class Solution {
  public:
    int paintWalls(const vector<int> &cost, const vector<int> &time) {
        static unsigned dp[501], pdp[501];

        const int n = cost.size();
        for (int i = 1; i <= 500; i++)
            pdp[i] = 1e9;

        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                const int paint = cost[i] + pdp[max(0, remain - time[i] - 1)];
                const int dont = pdp[remain];
                dp[remain] = min(paint, dont);
            }
            swap(dp, pdp);
        }

        return pdp[n];
    }
};
