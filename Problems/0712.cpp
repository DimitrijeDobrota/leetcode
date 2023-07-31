class Solution {
  int dp[1001][1001];
  int rec(const string &s1, const string &s2, int l1, int l2) {
    if (l1 >= s1.size() && l2 >= s2.size()) return 0;
    if (dp[l1][l2] != -1) return dp[l1][l2];

    int res = INT_MAX;
    if (s1[l1] == s2[l2]) res = min(res, rec(s1, s2, l1 + 1, l2 + 1));
    res = min(res, s1[l1] + rec(s1, s2, l1 + 1, l2));
    res = min(res, s2[l2] + rec(s1, s2, l1, l2 + 1));

    return dp[l1][l2] = res;
  }

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }
  int minimumDeleteSum(const string &s1, const string &s2) {
    for (int i = s1.size() - 1, sum = 0; i >= 0; i--)
      dp[i][s2.size()] = sum += s1[i];
    for (int i = s2.size() - 1, sum = 0; i >= 0; i--)
      dp[s1.size()][i] = sum += s2[i];

    return rec(s1, s2, 0, 0);
  }
};
