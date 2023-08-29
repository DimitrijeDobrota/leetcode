class Solution {
  public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        static constexpr const int offset_x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        static constexpr const int offset_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        int hit[64] = {0};
        vector<vector<int>> res;

        for (const auto &queen : queens)
            hit[queen[0] * 8 + queen[1]] = true;

        for (int i = 0; i < 8; i++) {
            int x = king[0] + offset_x[i], y = king[1] + offset_y[i];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (hit[x * 8 + y]) {
                    res.push_back({x, y});
                    break;
                }
                x += offset_x[i], y += offset_y[i];
            }
        }

        return res;
    }
};
