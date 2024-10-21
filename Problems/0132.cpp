class Solution {
  public:
    int minCut(const string &s) const {
        static bool dp[2001][2001];
        static int cut[2001];
        const int n = s.size();

        memset(dp, 0x00, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int mini = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 3 || dp[i - 1][j + 1])) {
                    mini = j == 0 ? 0 : min(mini, cut[j - 1] + 1);
                    dp[i][j] = true;
                }
            }
            cut[i] = mini;
        }

        return cut[n - 1];
    }
};
