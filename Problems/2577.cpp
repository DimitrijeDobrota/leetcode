class Solution {
  public:
    int minimumTime(vector<vector<int>> &grid) const {
        const int n = size(grid), m = size(grid[0]);

        static const int offset[] = {-1, 0, 1, 0, -1};
        const auto is_valid = [&](const int x, const int y) {
            return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] >= 0;
        };

        using type_t = tuple<int, int, int>;
        priority_queue<type_t, vector<type_t>, greater<>> pq;

        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        for (pq.emplace(0, 0, 0); !pq.empty();) {
            const auto [time, a, b] = pq.top();
            pq.pop();

            if (a == n - 1 && b == m - 1) return time;

            for (int k = 0; k < 4; k++) {
                const int x = a + offset[k + 1];
                const int y = b + offset[k];

                if (!is_valid(x, y)) continue;

                const int req = grid[x][y];
                if (time + 1 >= req)
                    pq.emplace(time + 1, x, y);
                else
                    pq.emplace(req + !((req - time) % 2), x, y);

                grid[x][y] = -1;
            }
        }

        return -1;
    }
};
