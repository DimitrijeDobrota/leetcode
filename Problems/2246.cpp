class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    int n = parent.size();

    vector<vector<int>> adj(n);
    vector<int> pc(n, 0), count(n);
    for (int i = 1; i < n; i++) pc[parent[i]]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (pc[i] == 0) q.push(i);

    int res = 0;
    while (true) {
      int crnt = q.front();
      q.pop();

      int mx1 = 0, mx2 = 0;
      for (int c : adj[crnt]) {
        int a = s[crnt] != s[c] ? count[c] : 0;
        if (a > mx1) {
          mx2 = mx1;
          mx1 = a;
        } else if (a > mx2) {
          mx2 = a;
        }
      }
      res = max(res, mx1 + mx2 + 1);
      count[crnt] = mx1 + 1;

      if (crnt == 0) break;
      int p = parent[crnt];
      adj[p].push_back(crnt);
      if (!--pc[p]) q.push(p);
    }

    return res;
  }
};
