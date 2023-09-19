class Solution {
    typedef bitset<512> bs_t;

  public:
    int maxEqualRowsAfterFlips(const vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        unordered_map<bs_t, int> um;
        for (int i = 0; i < n; i++) {
            bs_t crnt;
            for (int j = 0; j < m; j++)
                crnt[j] = matrix[i][j] != matrix[i][0];
            res = max(res, ++um[crnt]);
        }
        return res;
    }
};
