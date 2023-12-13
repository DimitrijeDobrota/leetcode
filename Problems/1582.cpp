class Solution {
  public:
    int numSpecial(const vector<vector<int>> &mat) const {
        const int n = mat.size(), m = mat[0].size();
        int row[101] = {0}, col[101] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
