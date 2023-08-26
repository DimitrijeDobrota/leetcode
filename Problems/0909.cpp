class Solution {
  public:
    int snakesAndLadders(vector<vector<int>> &board) {
        const int n = board.size();

        // index directy with a square instead of a coordinate
        vector<int> cord(n * n + 1);

        int crnt = 1, x = n - 1, y = 0, dir = 1;
        while (crnt <= n * n) {
            cord[crnt] = board[x][y];
            if (crnt % n == 0)
                x--, dir *= -1;
            else
                y += dir;
            crnt++;
        }

        vector<bool> visited(n * n + 1);
        queue<pair<int, int>> q;
        int res = INT_MAX;

        q.push({1, 0}), visited[1] = true;
        while (!q.empty()) {
            auto [crnt, move] = q.front();
            q.pop();

            if (crnt == n * n) return move;

            for (int i = 0; i < 6; i++) {
                if (++crnt > n * n) break;
                int square = cord[crnt] == -1 ? crnt : cord[crnt];
                if (visited[square]) continue;
                visited[square] = true;
                q.push({square, move + 1});
            }
        }
        return -1;
    }
};
