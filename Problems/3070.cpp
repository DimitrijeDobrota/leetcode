static const auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
  public:
    int countSubmatrices(vector<vector<int>> &grid, int k) const {
        int n = size(grid), m = size(grid[0]), res = grid[0][0] <= k;

        for (int i = 1, acc = grid[0][0]; i < n; i++) {
            grid[i][0] = acc += grid[i][0];
            if (grid[i][0] <= k)
                res++;
            else {
                n = i;
                break;
            }
        }

        for (int j = 1, acc = grid[0][0]; j < m; j++) {
            grid[0][j] = acc += grid[0][j];
            if (grid[0][j] <= k)
                res++;
            else {
                m = j;
                break;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                if (grid[i][j] <= k)
                    res++;
                else {
                    m = j;
                    break;
                }
            }
        }

        return res;
    }
};
