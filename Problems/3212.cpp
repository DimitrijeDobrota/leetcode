class Solution {
  public:
    int numberOfSubmatrices(const vector<vector<char>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        vector<vector<int>> x(n + 1, vector(m + 1, 0));
        vector<vector<int>> y(n + 1, vector(m + 1, 0));
        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y');
                if (x[i][j] > 0 && x[i][j] == y[i][j]) res++;
            }
        }

        return res;
    }
};
