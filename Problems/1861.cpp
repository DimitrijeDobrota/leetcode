#pragma GCC optimize(fast);
static auto _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
  public:
    vector<vector<char>> rotateTheBox(const vector<vector<char>> &box) const {
        const int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector(n, '.'));

        for (int i = 0; i < n; i++) {
            for (int j = m - 1, limit = m; j >= 0; j--) {
                if (box[i][j] == '.') continue;
                if (box[i][j] == '*') {
                    res[j][n - i - 1] = '*';
                    limit = j;
                    continue;
                }
                res[--limit][n - i - 1] = '#';
            }
        }

        return res;
    }
};
