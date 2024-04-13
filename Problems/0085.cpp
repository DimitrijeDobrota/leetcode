class Solution {
  public:
    int maximalRectangle(const vector<vector<char>> &matrix) const {
        const int n = size(matrix), m = size(matrix[0]);
        static int dp[202][202] = {0};
        int res = 0;

        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = 0;
            for (int j = m - 1, acc = 0; j >= 0; j--) {
                dp[i][j] = matrix[i][j] == '1' ? dp[i][j + 1] + 1 : 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = i, len = m; l < n && matrix[l][j] == '1'; l++) {
                    len = min(len, dp[l][j]);
                    res = max(res, (l - i + 1) * len);
                }
            }
        }

        return res;
    }
};
