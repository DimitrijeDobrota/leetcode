
// Return true works as Alice is always the winner
class Solution {
    int dp[501][501];
    int score(const vector<int> &piles, int i, int j, int crnt) {
        if (j < i) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(score(piles, i + 1, j, -(crnt + piles[i])),
                              score(piles, i, j - 1, -(crnt + piles[j])));
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    bool stoneGame(const vector<int> &piles) { return score(piles, 0, piles.size() - 1, 0) <= 0; }
};
