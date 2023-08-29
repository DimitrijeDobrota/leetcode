
// Solution idea
class Solution {
  public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        const int n = grid.size(), m = grid[0].size(), l = n - 1;
        vector<unordered_set<int>> vus(m + n - 1);
        vector<vector<int>> res(n, vector(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = vus[j - i + l].size();
                vus[j - i + l].insert(grid[i][j]);
            }
        }

        for (int i = 0; i < m + n - 1; i++)
            vus[i].clear();

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = abs((int)(res[i][j] - vus[j - i + l].size()));
                vus[j - i + l].insert(grid[i][j]);
            }
        }

        return res;
    }
};

// Optimized solution
class Solution {
  public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int vus[101][51] = {0}, count[101] = {0};
        const int n = grid.size(), m = grid[0].size(), l = n - 1;
        vector<vector<int>> res(n, vector(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = count[j - i + l];
                if (vus[j - i + l][grid[i][j]] != 1) {
                    vus[j - i + l][grid[i][j]] = 1;
                    count[j - i + l]++;
                }
            }
        }

        for (int i = 0; i < m + n - 1; i++)
            count[i] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = abs(res[i][j] - count[j - i + l]);
                if (vus[j - i + l][grid[i][j]] != 2) {
                    vus[j - i + l][grid[i][j]] = 2;
                    count[j - i + l]++;
                }
            }
        }

        return res;
    }
};
