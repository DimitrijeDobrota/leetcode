class Solution {
  public:
    vector<vector<int>> transpose(const vector<vector<int>> &matrix) const {
        const int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> res(m, vector(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
