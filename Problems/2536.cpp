class Solution {
  public:
    vector<vector<int>> rangeAddQueries(int n, const vector<vector<int>> &queries) const {
        vector<vector<int>> mat(n, vector(n, 0));

        for (const auto &query : queries) {
            mat[query[0]][query[1]]++;
            if (query[2] + 1 < n && query[3] + 1 < n) mat[query[2] + 1][query[3] + 1]++;
            if (query[2] + 1 < n) mat[query[2] + 1][query[1]]--;
            if (query[3] + 1 < n) mat[query[0]][query[3] + 1]--;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0, acc = 0; j < n; j++) {
                mat[i][j] = acc += mat[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0, acc = 0; i < n; i++) {
                mat[i][j] = acc += mat[i][j];
            }
        }

        return mat;
    }
};
