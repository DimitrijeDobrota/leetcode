class Solution {
  int m, n;
  vector<int> ox = {-1, 1, 0, 0};
  vector<int> oy = {0, 0, -1, 1};

  bool is_valid(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

  bool is_exit(int x, int y) {
    return x == 0 || x == m - 1 || y == 0 || y == n - 1;
  }

public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    m = maze.size();
    n = maze[0].size();

    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    for (int lvl = 0; !q.empty(); lvl++) {
      for (int t = q.size(); t > 0; t--) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // cout << x << " " << y << endl;

        if (maze[x][y] == '+') continue;

        if ((x != entrance[0] || y != entrance[1]) && is_exit(x, y)) return lvl;

        maze[x][y] = '+';

        for (int i = 0; i < 4; i++) {
          int nx = x + ox[i];
          int ny = y + oy[i];
          if (is_valid(nx, ny) && maze[nx][ny] != '+') q.push({nx, ny});
        }
      }
    }

    return -1;
  }
};
