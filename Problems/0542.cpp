class Solution {
  queue<pair<int, int>> q;
  int m, n;

  typedef vector<vector<int>> vvi;

  int valid(int sr, int sc) { return sr >= 0 && sr < m && sc >= 0 && sc < n; }

  void add(vvi &mat, int sr, int sc) {
    cout << sr << " " << sc << " valid is: " << valid(sr, sc) << endl;
    if (valid(sr, sc) && mat[sr][sc] != 0) q.push(make_pair(sr, sc));
  }

  void ff(vvi &mat, vvi &res, int sr, int sc) {
    q.push(make_pair(sr, sc));
    for (int lvl = 0; !q.empty(); lvl++) {
      for (int t = q.size(); t > 0; t--) {
        int sr = q.front().first;
        int sc = q.front().second;
        cout << "lvl" << lvl << ": " << sr << " " << sc << endl;
        q.pop();

        if (!res[sr][sc] || res[sr][sc] > lvl)
          res[sr][sc] = lvl;
        else
          continue;

        cout << "adding" << endl;
        add(mat, sr + 1, sc);
        add(mat, sr - 1, sc);
        add(mat, sr, sc + 1);
        add(mat, sr, sc - 1);
      }
    }
    cout << "end FF" << endl;
  }

public:
  vector<vector<int>> updateMatrix(vvi &mat) {
    m = mat.size();
    n = mat[0].size();

    cout << m << " " << n << endl;

    vvi res(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (mat[i][j] == 0) ff(mat, res, i, j);

    return res;
  }
};
