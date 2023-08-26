class Solution {
    static const int MOD = 1E9 + 7;
    int dp[101][201];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }

    int countRoutes(const vector<int> &loc, int start, int finish, int fuel) {
        if (fuel < 0) return 0;
        if (dp[start][fuel] >= 0) return dp[start][fuel];

        int res = (start == finish);
        for (int i = 0; i < loc.size(); i++) {
            if (i == start) continue;
            int solution = countRoutes(loc, i, finish, fuel - abs(loc[start] - loc[i]));
            res = (res + solution) % MOD;
        }
        return dp[start][fuel] = res;
    }
};
