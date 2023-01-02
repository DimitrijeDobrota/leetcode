class Solution {
public:
  bool canFinish(int n, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> count(n, 0);
    int num = 0;

    for (auto &p : prerequisites) {
      adj[p[0]].push_back(p[1]);
      count[p[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int root = q.front();
      q.pop();
      n--;
      for (int c : adj[root])
        if (!--count[c]) q.push(c);
    }

    return n == 0;
  }
};
