class Solution {
  public:
    long long maxMatrixSum(const vector<vector<int>> &matrix) const {
        const int n = size(matrix);
        int count = 0, mini = INT_MAX;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += abs(matrix[i][j]);
                count += matrix[i][j] < 0;
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        return count % 2 == 0 ? res : res - 2 * mini;
    }
};
