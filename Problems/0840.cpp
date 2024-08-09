class Solution {
  public:
    int numMagicSquaresInside(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        int res = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] != 5) continue;

                if (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] != 15) continue;
                if (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] != 15) continue;

                unordered_set<int> us;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (grid[k][l] < 1 || grid[k][l] > 9) goto next;
                        if (us.count(grid[k][l])) goto next;
                        us.insert(grid[k][l]);
                    }
                }

                res++;
            next:;
            }
        }

        return res;
    }
};
