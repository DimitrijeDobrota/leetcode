class Solution {
  public:
    int calculateMinimumHP(const vector<vector<int>> &dungeon) const {
        const int n = size(dungeon), m = size(dungeon[0]);
        vector<int> dp(n + 1, INT_MAX);

        dp[n - 1] = 1;
        for (int j = m - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                const int need = min(dp[i], dp[i + 1]) - dungeon[i][j];
                dp[i] = max(need, 1);
            }
        }

        return dp[0];
    }
};
