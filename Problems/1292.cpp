class Solution {
    mutable int n, m;

    bool exists(const vector<vector<int>> &mat, const int threshold, const int side) const {
        for (int i = 0; i < n - side; i++) {
            for (int j = 0; j < m - side; j++) {
                int crnt = mat[i + side][j + side];
                if (i > 0) crnt -= mat[i - 1][j + side];
                if (j > 0) crnt -= mat[i + side][j - 1];
                if (i > 0 && j > 0) crnt += mat[i - 1][j - 1];
                if (crnt <= threshold) return true;
            }
        }
        return false;
    }

  public:
    int maxSideLength(vector<vector<int>> &mat, const int threshold) const {
        n = size(mat), m = size(mat[0]);

        for (int i = 0, acc = 0; i < n; i++)
            mat[i][0] = acc += mat[i][0];
        for (int j = 0, acc = 0; j < m; j++)
            mat[0][j] = acc += mat[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }

        int low = 1, high = min(n, m);

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            if (exists(mat, threshold, mid - 1))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};
