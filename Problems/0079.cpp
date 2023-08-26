class Solution {
    typedef vector<vector<char>> Matrix;
    typedef vector<vector<bool>> Marked;
    const vector<pair<int, int>> offsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int n, m;
    int valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    string word;
    bool dfs(const Matrix &mat, Marked &mark, int a, int b, int got) {
        if (got == word.size()) return true;

        mark[a][b] = true;
        for (auto [oa, ob] : offsets) {
            int x = a + oa, y = b + ob;
            if (!valid(x, y) || mark[x][y] || mat[x][y] != word[got]) continue;
            if (dfs(mat, mark, x, y, got + 1)) return true;
        }
        mark[a][b] = false;

        return false;
    }

  public:
    bool exist(const Matrix &board, string word) {
        n = board.size(), m = board[0].size();
        this->word = word;

        Marked visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != word[0]) continue;
                if (dfs(board, visited, i, j, 1)) return true;
            }
        }

        return false;
    }
};
