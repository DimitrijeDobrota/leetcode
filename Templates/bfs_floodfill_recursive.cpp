// Matrix BFS/Flood fill Recursive

typedef vector<vector<int>> Matrix;
typedef vector<vector<bool>> Marked;
const vector<pair<int, int>> offsets = {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

int n, m;
int valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

bool dfs(const Matrix &mat, Marked &mark, int a, int b) {
  if (got == word.size()) return true;

  mark[a][b] = true;
  for (auto [oa, ob] : offsets) {
    int x = a + oa, y = b + ob;
    if (!valid(x, y) || mark[x][y]) continue;
    if (dfs(mat, mark, x, y)) return true;
  }
  mark[a][b] = false;

  return false;
}
