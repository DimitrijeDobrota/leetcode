class Solution {
    int n;

    bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        n = grid.size();

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<pair<int, int>> offsets = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                          {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            if (a == n - 1 && b == n - 1) return grid[a][b] + 1;
            for (auto [ox, oy] : offsets) {
                int x = a + ox, y = b + oy;
                if (!valid(x, y) || grid[x][y] > 0) continue;
                grid[x][y] = grid[a][b] + 1;
                q.push({x, y});
            }
        }
        return -1;
    }
};
