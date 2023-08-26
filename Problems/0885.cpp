class Solution {
  public:
    vector<vector<int>> spiralMatrixIII(const int rows, const int cols, int x, int y) {
        static const int8_t offset_x[4] = {0, 1, 0, -1};
        static const int8_t offset_y[4] = {1, 0, -1, 0};
        vector<vector<int>> res;
        res.reserve(rows * cols);
        int dir = 0, cnt = 1, len = 1;

        while (res.size() < rows * cols) {
            for (int i = 0; i < len; i++) {
                if (x >= 0 && x < rows && y >= 0 && y < cols) res.push_back({x, y});
                x += offset_x[dir], y += offset_y[dir];
            }
            len += dir & 1;
            dir = (dir + 1) & 0x3;
        }

        return res;
    }
};
