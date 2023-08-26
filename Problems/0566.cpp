class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> nmat(r, vector<int>(c));

        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nmat[x][y] = mat[i][j];
                y++;
                x += y / c;
                y %= c;
            }
        }

        return nmat;
    }
};
