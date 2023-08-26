class Solution {
    typedef tuple<int, int, char> record;

    int cantor(int a, int b) { return (a + b + 1) * (a + b) / 2 + b; }

    int hash(const record &r) { return cantor(get<0>(r), cantor(get<1>(r), get<2>(r))); }

    int n, m;
    int valid(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

  public:
    int shortestPathAllKeys(const vector<string> &grid) {
        static const int offset_x[] = {0, 0, 1, -1};
        static const int offset_y[] = {1, -1, 0, 0};
        n = grid.size(), m = grid[0].size();

        int start_x = -1, start_y = -1, goal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@')
                    start_x = i, start_y = j;
                else if (islower(grid[i][j]))
                    goal |= 1 << (grid[i][j] & 0xF);
            }
        }

        unordered_set<int> visited;
        queue<record> q;
        q.push({start_x, start_y, 0});
        visited.insert(hash(q.front()));
        for (int step = 0; !q.empty(); step++) {
            for (int k = q.size(); k > 0; k--) {
                auto [x, y, keys] = q.front();
                q.pop();
                if (keys == goal) return step;
                for (int k = 0; k < 4; k++) {
                    int i = x + offset_x[k], j = y + offset_y[k], key = keys;
                    if (!valid(i, j) || grid[i][j] == '#') continue;
                    if (isupper(grid[i][j]) && !(key & (1 << (grid[i][j] & 0xF)))) continue;
                    if (islower(grid[i][j])) key |= 1 << (grid[i][j] & 0xF);
                    const record r = {i, j, key};
                    if (!visited.count(hash(r))) {
                        visited.insert(hash(r));
                        q.push(r);
                    }
                }
            }
        }

        return -1;
    }
};
