class Solution {
  typedef vector<vector<char>> Matrix;
  typedef queue<pair<int, int>> Queue;
  const vector<pair<int, int>> offsets = {
      { 0,  1},
      { 0, -1},
      { 1,  0},
      {-1,  0}
  };

  int n, m;

  int valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

  void dfs(Matrix &board, int x, int y) {
    Queue q;

    q.push({x, y}), board[x][y] = '#';
    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      for (auto [oa, ob] : offsets) {
        int x = a + oa, y = b + ob;
        if (!valid(x, y) || board[x][y] == 'X' || board[x][y] != 'O') continue;
        board[x][y] = '#';
        q.push({x, y});
      }
    }
  }

public:
  void solve(Matrix &board) {
    n = board.size(), m = board[0].size();

    unordered_set<int> convert;
    Queue q;
    int group = 0;

    for (int i = 0; i < n; i++) {
      if (board[i][0] == 'O') dfs(board, i, 0);
      if (board[i][m - 1] == 'O') dfs(board, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
      if (board[0][j] == 'O') dfs(board, 0, j);
      if (board[n - 1][j] == 'O') dfs(board, n - 1, j);
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (board[i][j] != 'X') board[i][j] = board[i][j] == 'O' ? 'X' : 'O';
  }
};
