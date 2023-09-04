class Solution {
  public:
    vector<vector<int>> findFarmland(const vector<vector<int>> &land) {
        const int n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!land[i][j] || (i > 0 && land[i - 1][j]) || (j > 0 && land[i][j - 1])) continue;
                int a = i, b = j;
                while (a < n && land[a][j])
                    a++;
                while (b < m && land[i][b])
                    b++;
                res.push_back({i, j, a - 1, b - 1});
            }
        }
        return res;
    }
};
