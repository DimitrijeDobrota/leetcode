class Solution {
    typedef vector<vector<int>> Matrix;
    typedef vector<vector<bool>> Marked;
    typedef queue<pair<int, int>> Queue;
    const vector<pair<int, int>> offsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int n, m;
    int valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    void dfs(Matrix &mat, Marked &mark, int x, int y) {
        if (mark[x][y]) return;
        Queue q;

        q.push({x, y}), mark[x][y] = true;
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (auto [oa, ob] : offsets) {
                int x = a + oa, y = b + ob;
                if (!valid(x, y) || mark[x][y] || mat[x][y] < mat[a][b]) continue;
                mark[x][y] = true;
                q.push({x, y});
            }
        }
    }

  public:
    vector<vector<int>> pacificAtlantic(Matrix &heights) {
        n = heights.size(), m = heights[0].size();
        Marked pac(n, vector<bool>(m, false)), atl(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, m - 1);
        }

        for (int i = 0; i < m; i++) {
            dfs(heights, pac, 0, i);
            dfs(heights, atl, n - 1, i);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});

        return res;
    }
};
