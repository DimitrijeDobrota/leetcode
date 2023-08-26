class Solution {
    vector<pair<int, int>> offset = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    bool valid(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

    int find(vector<vector<int>> &grid, int x, int y, int obs) {
        stack<pair<int, int>> st;
        st.push({x, y});

        int count = 0, goal = m * n - obs - 1, crnt = 0;
        while (!st.empty()) {
            auto p = st.top();

            if (grid[p.first][p.second] == 3) {
                st.pop();
                grid[p.first][p.second] = 0;
                crnt--;
                continue;
            }

            grid[p.first][p.second] = 3;
            crnt++;
            for (auto &o : offset) {
                int x = p.first + o.first;
                int y = p.second + o.second;
                if (!valid(x, y) || grid[x][y] == 3 || grid[x][y] == -1) continue;
                if (grid[x][y] == 2)
                    count += crnt == goal;
                else
                    st.push({x, y});
            }
        }
        return count;
    }

  public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();

        int x, y, count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    x = i, y = j;
                else if (grid[i][j] == -1)
                    count++;

        return find(grid, x, y, count);
    }
};
