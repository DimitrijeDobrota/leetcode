class Solution {
  public:
    int findMaxForm(const vector<string> &strs, int m, int n) const {
        static int dp[101][101];

        memset(dp, 0x00, sizeof(dp));
        for (const auto &s : strs) {
            const int zero = count(begin(s), end(s), '0');
            const int one = size(s) - zero;
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
                }
            }
        }

        return dp[m][n];
    }
};
