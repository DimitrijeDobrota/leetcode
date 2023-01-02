class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    const int n = patience.size();
    vector<vector<int>> adj(n, vector<int>());

    for (auto &p : edges) {
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]);
    }

    const int master = 0;
    int time = 0;
    vector<int> dist(n, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int root = q.front();
      q.pop();
      for (int c : adj[root]) {
        if (!dist[c] && c != master) {
          dist[c] = dist[root] + 1;
          time = max(time, ((2 * dist[c] - 1) / patience[c]) * patience[c] +
                               2 * dist[c]);
          q.push(c);
        }
      }
    }
    return time + 1;
  }
};
