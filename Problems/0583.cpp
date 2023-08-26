class Solution {
    vector<vector<int>> dp;

    int solve(const string &s1, const string &s2, int i, int j) {
        if (i == s1.size() && j == s2.size()) return 0;
        if (i == s1.size() || j == s2.size()) return max(s1.size() - i, s2.size() - j);
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (s1[i] == s2[j]) return solve(s1, s2, i + 1, j + 1);
        return dp[i][j] = 1 + min(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }

  public:
    int minDistance(const string &word1, const string &word2) {
        dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, INT_MAX));
        return solve(word1, word2, 0, 0);
    }
};
