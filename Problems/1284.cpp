class Solution {
  public:
    int minFlips(const vector<vector<int>> &mat) const {
        static const int offset[] = {-1, 0, 1, 0, -1};
        const int n = size(mat), m = size(mat[0]);
        unsigned res = -1;

        const auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; };

        for (unsigned mask = 0; mask < 1 << (n * m); mask++) {
            auto grid = mat;

            for (unsigned k = 0, crnt = mask; crnt; crnt >>= 1, k++) {
                if (!(crnt & 1)) continue;

                const int a = k / m, b = k % m;
                for (int k = 0; k < 4; k++) {
                    const int x = a + offset[k + 1];
                    const int y = b + offset[k];

                    if (!valid(x, y)) continue;
                    grid[x][y] = !grid[x][y];
                }
                grid[a][b] = !grid[a][b];
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j]) goto next;
                }
            }

            res = min(res, (unsigned)popcount(mask));
        next:;
        }

        return res;
    }
};
