class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                q.push(make_pair(i, j));
                cnt++;
                while (!q.empty()) {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') continue;
                    grid[i][j] = '0';
                    q.push(make_pair(i + 1, j));
                    q.push(make_pair(i - 1, j));
                    q.push(make_pair(i, j + 1));
                    q.push(make_pair(i, j - 1));
                }
            }
        }
        return cnt;
    }
};
