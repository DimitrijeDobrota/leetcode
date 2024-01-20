class Solution {
  public:
    bool checkValidGrid(const vector<vector<int>> &grid) const {
        static const int offset_x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        static const int offset_y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        const int n = size(grid), m = size(grid[0]);

        int x = 0, y = 0;
        if (grid[0][0] != 0) return false;
        for (int cnt = 1; cnt < n * m; cnt++) {
            for (int k = 0; k < 8; k++) {
                const int a = x + offset_x[k];
                const int b = y + offset_y[k];
                if (a < 0 || b < 0 || a >= n || b >= m) continue;
                if (grid[a][b] == cnt) {
                    x = a, y = b;
                    goto next;
                }
            }
            return false;
        next:;
        }
        return true;
    }
};
