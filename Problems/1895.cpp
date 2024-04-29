class Solution {
  public:
    int largestMagicSquare(const vector<vector<int>> &grid) const {
        static int row[51][51] = {}, col[51][51] = {};
        const int n = size(grid), m = size(grid[0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                row[i + 1][j + 1] = row[i + 1][j] + grid[i][j];
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++)
                col[i + 1][j + 1] = col[i][j + 1] + grid[i][j];
        }

        for (int k = min(n, m); k > 1; k--) {
            for (int i = k; i <= n; i++) {
                for (int j = k; j <= m; j++) {
                    const int r = row[i][j] - row[i][j - k];
                    const int c = col[i][j] - col[i - k][j];
                    int d1 = 0, d2 = 0;

                    if (r != c) goto nothing;
                    for (int l = 0; l < k; l++) {
                        if (r != row[i - l][j] - row[i - l][j - k]) goto nothing;
                        if (c != col[i][j - l] - col[i - k][j - l]) goto nothing;
                        d1 += grid[i - k + l][j - k + l];
                        d2 += grid[i - l - 1][j - k + l];
                    }

                    if (d1 != d2 || d1 != r) goto nothing;

                    return k;
                nothing:;
                }
            }
        }

        return 1;
    }
};
