class Solution {
  public:
    int digArtifacts(int n, const vector<vector<int>> &artifacts, const vector<vector<int>> &dig) const {
        vector<vector<int>> grid(n, vector(n, 0));
        for (const auto &d : dig)
            grid[d[0]][d[1]] = 1;

        for (int i = 0, acc = 0; i < n; i++)
            grid[i][0] = acc += grid[i][0];
        for (int i = 0, acc = 0; i < n; i++)
            grid[0][i] = acc += grid[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        int res = 0;
        for (const auto &art : artifacts) {
            const int goal = (art[2] - art[0] + 1) * (art[3] - art[1] + 1);
            int crnt = grid[art[2]][art[3]];
            crnt -= art[0] > 0 ? grid[art[0] - 1][art[3]] : 0;
            crnt -= art[1] > 0 ? grid[art[2]][art[1] - 1] : 0;
            crnt += art[0] > 0 && art[1] > 0 ? grid[art[0] - 1][art[1] - 1] : 0;
            res += goal == crnt;
        }

        return res;
    }
};
