class Solution {
  int dp[8][16384];

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }

  int maxScore(vector<int> &n, int i = 1, int mask = 0) {
    if (i > n.size() / 2) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    dp[i][mask] = 0;
    for (int j = 0; j < n.size(); j++) {
      for (auto k = j + 1; k < n.size(); k++) {
        int new_mask = (1 << j) | (1 << k);
        if ((mask & new_mask)) continue;
        dp[i][mask] = max(dp[i][mask], i * gcd(n[j], n[k]) +
                                           maxScore(n, i + 1, mask + new_mask));
      }
    }
    return dp[i][mask];
  }
};
