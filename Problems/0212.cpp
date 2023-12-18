class Solution {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        bool &terminate = reinterpret_cast<bool &>(children[0]);

        void insert(const string &s) {
            Node *crnt = this;
            for (const char c : s) {
                const int idx = c & 0x1F;
                if (!crnt->children[idx]) crnt->children[idx] = new Node();
                crnt = crnt->children[idx];
            }
            crnt->terminate = true;
        }
    };

    int n, m;
    vector<string> res;

    void dfs(vector<vector<char>> &board, Node *trie, int x, int y) {
        const char c = board[x][y], idx = c & 0x1F;
        if (c == '#' || !(trie = trie->children[idx])) return;

        res.back().push_back(c);
        if (trie->terminate) {
            res.push_back(res.back());
            trie->terminate = false;
        }

        board[x][y] = '#';
        if (x > 0) dfs(board, trie, x - 1, y);
        if (y > 0) dfs(board, trie, x, y - 1);
        if (x < n) dfs(board, trie, x + 1, y);
        if (y < m) dfs(board, trie, x, y + 1);
        board[x][y] = c;
        res.back().pop_back();
    }

  public:
    vector<string> findWords(vector<vector<char>> &board, const vector<string> &words) {
        Node *trie = new Node();
        for (const string &word : words)
            trie->insert(word);

        n = board.size() - 1, m = board[0].size() - 1;

        res.push_back("");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dfs(board, trie, i, j);
            }
        }
        res.pop_back();

        return res;
    }
};
