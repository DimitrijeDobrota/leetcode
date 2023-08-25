class Solution {
  short int dp[101][101];
  bool rec(const string &s1, const string &s2, const string &s3, int i = 0,
           int j = 0, int k = 0) {
    if (k == s3.size()) return true;
    if (dp[i][j] != -1) return dp[i][j];

    if (i != s1.size() && s1[i] == s3[k] && rec(s1, s2, s3, i + 1, j, k + 1))
      return dp[i][j] = true;

    if (j != s2.size() && s2[j] == s3[k] && rec(s1, s2, s3, i, j + 1, k + 1))
      return dp[i][j] = true;

    return dp[i][j] = false;
  }

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }
  bool isInterleave(const string &s1, const string &s2, const string &s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    return rec(s1, s2, s3);
  }
};
