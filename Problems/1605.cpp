class Solution {
  public:
    vector<vector<int>> restoreMatrix(vector<int> &row, vector<int> &col) {
        int m = row.size(), n = col.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = min(row[i], col[j]);
                row[i] -= res[i][j], col[j] -= res[i][j];
            }
        }
        return res;
    }
};
