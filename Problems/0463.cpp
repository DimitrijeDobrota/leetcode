class Solution {
  public:
    int islandPerimeter(const vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);
        static int offset[] = {-1, 0, 1, 0, -1};
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;

                res += 4;
                for (int k = 0; k < 4; k++) {
                    const int x = i + offset[k];
                    const int y = j + offset[k + 1];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    res -= grid[x][y] == 1;
                }
            }
        }

        return res;
    }
};
