class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int add = (board[i][j] & 1) << 1;
                for (int k = max(i - 1, 0); k <= min(n - 1, i + 1); k++) {
                    for (int l = max(j - 1, 0); l <= min(m - 1, j + 1); l++) {
                        board[k][l] += add;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = board[i][j] == 7 || board[i][j] == 9 || board[i][j] == 6;
            }
        }
    }
};
