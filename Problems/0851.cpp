class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    const int n = quiet.size();
    vector<vector<int>> adj(n);
    vector<int> count(n);
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);

    for (auto &p : richer) {
      adj[p[0]].push_back(p[1]);
      count[p[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int crnt = q.front();
      q.pop();
      for (int &c : adj[crnt]) {
        if (quiet[res[c]] > quiet[res[crnt]]) res[c] = res[crnt];
        if (!--count[c]) q.push(c);
      }
    }
    return res;
  }
};
