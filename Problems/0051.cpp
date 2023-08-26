class Solution {
    vector<vector<string>> res;
    vector<string> board;
    unordered_set<int> used;
    int n;

    bool valid(int row, int col) { return row >= 0 && row < n && col >= 0 && col < n; }

    bool safe(int row, int col) {
        static vector<pair<int, int>> ofsts = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        if (used.count(col)) return false;
        for (auto &ofst : ofsts) {
            int a = row + ofst.first, b = col + ofst.second;
            while (valid(a, b)) {
                if (board[a][b] == 'Q') return false;
                a += ofst.first, b += ofst.second;
            }
        }
        return true;
    }

    void rec(int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!safe(row, i)) continue;
            used.insert(i);
            board[row][i] = 'Q';
            rec(row + 1);
            used.erase(i);
            board[row][i] = '.';
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board = vector<string>(n, string(n, '.'));
        rec(0);
        return res;
    }
};
