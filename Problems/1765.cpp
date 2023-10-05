class Solution {
    typedef tuple<int, int> record;

  public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        static const int offset[] = {-1, 0, 1, 0, -1};
        const int n = isWater.size(), m = isWater[0].size();

        queue<record> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j])
                    isWater[i][j] = 0, q.push({i, j});
                else
                    isWater[i][j] = INT_MAX;
            }
        }

        while (!q.empty()) {
            for (int k = q.size(); k > 0; k--) {
                const auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    const int x = i + offset[k], y = j + offset[k + 1];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (isWater[x][y] != INT_MAX) continue;
                    isWater[x][y] = isWater[i][j] + 1;
                    q.push({x, y});
                }
            }
        }

        return isWater;
    }
};
