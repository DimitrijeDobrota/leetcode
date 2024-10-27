class Solution {
  public:
    int countSquares(vector<vector<int>> &matrix) const {
        const int n = size(matrix), m = size(matrix[0]);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; res += matrix[i][j], j++) {
                if (matrix[i][j] && i && j) {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
                }
            }
        }

        return res;
    }
};
