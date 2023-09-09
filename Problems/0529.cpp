class Solution {
  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, const vector<int> &click) {
        const int n = board.size(), m = board[0].size();

        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        if (board[click[0]][click[1]] != 'E') return board;

        queue<pair<int, int>> q({{click[0], click[1]}});
        while (!q.empty()) {
            const auto [x, y] = q.front();
            q.pop();
            if (board[x][y] != 'E') continue;

            int count = 0;
            for (int i = max(x - 1, 0); i <= min(n - 1, x + 1); i++) {
                for (int j = max(y - 1, 0); j <= min(m - 1, y + 1); j++) {
                    if (board[i][j] == 'M') count++;
                }
            }

            if (count != 0) {
                board[x][y] = '0' + count;
                continue;
            }

            board[x][y] = 'B';
            for (int i = max(x - 1, 0); i <= min(n - 1, x + 1); i++) {
                for (int j = max(y - 1, 0); j <= min(m - 1, y + 1); j++) {
                    if (board[i][j] == 'E') q.push({i, j});
                }
            }
        }

        return board;
    }
};
