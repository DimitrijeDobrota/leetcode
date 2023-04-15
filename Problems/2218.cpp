class Solution {
  int dp[1001][2001] = {0};

public:
  int maxValueOfCoins(const vector<vector<int>> &piles, int left,
                      int pile = 0) {
    if (!left || pile >= piles.size()) return 0;
    if (dp[pile][left]) return dp[pile][left];

    int res = maxValueOfCoins(piles, left, pile + 1), sum = 0;
    for (int i = 0; i < piles[pile].size() && i < left; i++) {
      res = max(res, (sum += piles[pile][i]) +
                         maxValueOfCoins(piles, left - i - 1, pile + 1));
    }

    return dp[pile][left] = res;
  }
};
