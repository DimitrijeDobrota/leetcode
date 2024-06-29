class Solution {
  public:
    int largest1BorderedSquare(vector<vector<int>> &grid) {
        static int top[101][101], left[101][101];
        const int n = size(grid), m = size(grid[0]);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                left[i][j] = grid[i - 1][j - 1] ? left[i][j - 1] + 1 : 0;
                top[i][j] = grid[i - 1][j - 1] ? top[i - 1][j] + 1 : 0;
            }
        }

        for (int s = min(m, n); s > 0; s--) {
            for (int i = 0; i <= n - s; i++) {
                for (int j = 0; j <= m - s; j++) {
                    if (top[i + s][j + 1] < s) continue;
                    if (top[i + s][j + s] < s) continue;
                    if (left[i + 1][j + s] < s) continue;
                    if (left[i + s][j + s] < s) continue;
                    return s * s;
                }
            }
        }

        return 0;
    }
};
