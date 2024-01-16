class Solution {
  public:
    int numSubmat(vector<vector<int>> &mat) const {
        const int n = size(mat), m = size(mat[0]);

        for (int j = 0; j < m; j++) {
            for (int i = 0, acc = 0; i < n; i++) {
                if (mat[i][j])
                    mat[i][j] = acc += 1;
                else
                    acc = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mini = mat[i][j];
                for (int k = j; k >= 0; k--) {
                    mini = min(mini, mat[i][k]);
                    if (!mini) break;
                    res += mini;
                }
            }
        }
        return res;
    }
};
