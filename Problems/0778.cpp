class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) const {
        priority_queue<tuple<int, int, int>> pq;
        const int n = size(grid);

        static const int offset[] = {-1, 0, 1, 0, -1};
        const auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; };

        pq.emplace(-grid[0][0], 0, 0);
        while (!pq.empty()) {
            const auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == n - 1) return -t;

            for (int k = 0; k < 4; k++) {
                const auto a = x + offset[k + 1];
                const auto b = y + offset[k];

                if (!valid(a, b) || grid[a][b] < 0) continue;
                pq.emplace(min(t, -grid[a][b]), a, b);
                grid[a][b] = -1;
            }
        }

        return -1;
    }
};
