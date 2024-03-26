class Solution {
  public:
    int countUnguarded(const int n, const int m, const vector<vector<int>> &guards,
                       const vector<vector<int>> &walls) const {
        const auto idx = [m](int x, int y) { return x * m + y; };

        bitset<100001> stop = 0, seen = 0;
        for (const auto &wall : walls)
            stop.set(idx(wall[0], wall[1]));
        for (const auto &guard : guards)
            stop.set(idx(guard[0], guard[1]));

        static const int offset[] = {-1, 0, 1, 0, -1};

        int res = m * n - size(walls) - size(guards);
        for (const auto &guard : guards) {
            for (int k = 0; k < 4; k++) {
                int x = guard[0] + offset[k], y = guard[1] + offset[k + 1];
                while (x >= 0 && x < n && y >= 0 && y < m) {
                    const int index = idx(x, y);
                    if (stop.test(index)) break;
                    if (!seen.test(index)) res--;
                    seen.set(index);
                    x += offset[k], y += offset[k + 1];
                }
            }
        }

        return res;
    }
};
