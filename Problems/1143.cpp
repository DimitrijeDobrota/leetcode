// Top-down DP
class Solution {
    int search(const string &text1, const string &text2, int si, int sj, vector<vector<int>> &dp) {
        if (si == text1.size() || sj == text2.size()) return 0;
        if (dp[si][sj] != -1) return dp[si][sj];
        int len = 0, i = si, j = sj;
        while (i < text1.size() && j < text2.size() && text1[i] == text2[j])
            i++, j++, len++;

        if (i == text1.size() || j == text2.size()) return dp[si][sj] = len;
        return dp[si][sj] = len + max(search(text1, text2, i + 1, j, dp), search(text1, text2, i, j + 1, dp));
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return search(text1, text2, 0, 0, dp);
    }
};

// Bottom-up DP
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); i++)
            for (int j = 0; j < text2.size(); j++)
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

        return dp.back().back();
    }
};
