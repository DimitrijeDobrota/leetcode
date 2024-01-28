class Solution {
  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) const {
        const int n = size(matrix), m = size(matrix[0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0, acc = 0; j < m; j++) {
                matrix[i][j] = acc += matrix[i][j];
            }
        }

        unordered_map<int, int> um;
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                um = {{0, 1}};
                int crnt = 0;
                for (int k = 0; k < n; k++) {
                    crnt += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += um[crnt - target];
                    um[crnt]++;
                }
            }
        }

        return res;
    }
};
