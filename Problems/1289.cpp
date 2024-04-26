class Solution {
  public:
    int minFallingPathSum(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        int first = 0, second = 0, pos = -1;

        for (auto i = 0; i < n; i++) {
            auto first2 = INT_MAX, second2 = INT_MAX, pos2 = -1;
            for (auto j = 0; j < m; j++) {
                const int crnt = grid[i][j] + (j != pos ? first : second);
                if (crnt < first2) {
                    second2 = first2;
                    first2 = crnt;
                    pos2 = j;
                } else {
                    second2 = min(second2, crnt);
                }
            }
            first = first2, second = second2, pos = pos2;
        }

        return first;
    }
};
