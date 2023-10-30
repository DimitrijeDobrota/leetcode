class Solution {
  public:
    int countServers(const vector<vector<int>> &grid) {
        const int n = grid.size(), m = grid[0].size();
        int row[256] = {0}, col[256] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) row[i]++, col[j]++;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) res += row[i] > 1 || col[j] > 1;
            }
        }

        return res;
    }
};
