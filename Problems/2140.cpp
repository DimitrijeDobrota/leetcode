class Solution {
  static const int size = 1E5 + 1;
  long long dp[size];

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }

  long long mostPoints(const vector<vector<int>> &questions, int i = 0) {
    if (i >= questions.size()) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(questions[i][0] +
                           mostPoints(questions, i + questions[i][1] + 1),
                       mostPoints(questions, i + 1));
  }
};
