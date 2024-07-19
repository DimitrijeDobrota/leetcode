class Solution {
  public:
    vector<int> luckyNumbers(const vector<vector<int>> &matrix) const {
        static int row[51], col[51];
        const int n = size(matrix);
        const int m = size(matrix[0]);
        vector<int> res;

        memset(row, 0x7F, sizeof(row));
        memset(col, 0x00, sizeof(col));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] != matrix[i][j]) continue;
                if (col[j] != matrix[i][j]) continue;
                res.push_back(matrix[i][j]);
            }
        }

        return res;
    }
};
