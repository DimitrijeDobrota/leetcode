class Solution {
  public:
    int longestIdealString(const string &s, int k) const {
        static int dp[256];
        int res = 0;

        memset(dp, 0x00, sizeof(dp));
        for (const char c : s) {
            for (int j = c - k; j <= c + k; j++)
                dp[c] = max(dp[c], dp[j]);
            res = max(res, ++dp[c]);
        }

        return res;
    }
};
