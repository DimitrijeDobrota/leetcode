class Solution {
  public:
    int minInsertions(string s) {
        int dp[501][501] = {0}, n = s.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i] == s[n - 1 - j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];
    }
};
