class Solution {
  const int MOD = 1e9 + 7;
  typedef pair<long long, int> road;

public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<road>> adj(n);
    for (auto &r : roads) {
      adj[r[0]].push_back({r[2], r[1]});
      adj[r[1]].push_back({r[2], r[0]});
    }

    priority_queue<road, vector<road>, greater<road>> pq;
    vector<long long> dist(n, LONG_MAX);
    vector<int> count(n);
    pq.push({0, 0});
    count[0] = 1;
    dist[0] = 0;
    while (!pq.empty()) {
      auto [w, e] = pq.top();
      pq.pop();
      if (w > dist[e]) continue;
      for (auto [time, v] : adj[e]) {
        if (dist[v] < w + time) continue;
        if (dist[v] == w + time) {
          count[v] = (count[v] + count[e]) % MOD;
          continue;
        }
        dist[v] = w + time;
        count[v] = count[e];
        pq.push({dist[v], v});
      }
    }
    return count[n - 1];
  }
};
