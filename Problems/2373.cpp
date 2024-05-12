class Solution {
  public:
    vector<vector<int>> largestLocal(const vector<vector<int>> &grid) const {
        const int n = size(grid);
        vector<vector<int>> res(n - 2, vector(n - 2, 0));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int k = i; k <= i + 2; k++) {
                    for (int l = j; l <= j + 2; l++) {
                        res[i][j] = max(res[i][j], grid[k][l]);
                    }
                }
            }
        }

        return res;
    }
};
