// Matrix BFS/Flood fill

typedef vector<vector<int>> Matrix;
typedef queue<pair<int, int>> Queue;
const vector<pair<int, int>> offsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
int valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

void dfs(Matrix &mat, int x, int y) {
    Queue q;

    q.push({x, y}), mat[x][y] = 2;
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for (auto [oa, ob] : offsets) {
            int x = a + oa, y = b + ob;
            if (!valid(x, y) || mat[x][y] == 0 || mat[x][y] != 1) continue;
            mat[x][y] = 2;
            q.push({x, y});
        }
    }
}
