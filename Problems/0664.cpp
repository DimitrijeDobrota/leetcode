class Solution {
    int dp[101][101];
    int rec(const string &s, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        int res = s.size(), j = -1;
        for (int i = l; i < r; i++) {
            if (s[i] != s[r] && j == -1) j = i;
            if (j != -1) res = min(res, 1 + rec(s, j, i) + rec(s, i + 1, r));
        }
        return dp[l][r] = j != -1 ? res : 0;
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int strangePrinter(string &s) {
        int j = 1;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != s[i - 1]) s[j++] = s[i];

        return rec(s, 0, j - 1) + 1;
    }
};
