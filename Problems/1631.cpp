class Solution {
    typedef tuple<unsigned, uint8_t, uint8_t> tile;

  public:
    int minimumEffortPath(const vector<vector<int>> &heights) {
        static unsigned efforts[101][101];
        const int n = heights.size(), m = heights[0].size();
        static const int dirs[5] = {-1, 0, 1, 0, -1};

        memset(efforts, 0xFF, sizeof(efforts));
        priority_queue<tile, vector<tile>, greater<tile>> pq;

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            const auto [effort, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return effort;

            for (int k = 0; k < 4; k++) {
                const int i = x + dirs[k], j = y + dirs[k + 1];
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                const unsigned crnt = max(effort, (unsigned)abs(heights[x][y] - heights[i][j]));
                if (crnt < efforts[i][j]) {
                    efforts[i][j] = crnt;
                    pq.push({crnt, i, j});
                }
            }
        }

        return -1;
    }
};
