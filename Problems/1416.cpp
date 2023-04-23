class Solution {
  static const int mod = 1E9 + 7;
  static const int size = 1E5 + 1;
  int dp[size];

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }

  int numberOfArrays(const string &s, int k, int crnt = 0) {
    if (crnt >= s.size()) return 1;
    if (s[crnt] == '0') return 0;
    if (dp[crnt] != -1) return dp[crnt];

    long long num = 0, res = 0;
    for (int i = crnt; i < s.size(); i++) {
      num = num * 10 + (s[i] - '0');
      if (num > k) break;
      res = (res + numberOfArrays(s, k, i + 1)) % mod;
    }

    return dp[crnt] = res;
  }
};
