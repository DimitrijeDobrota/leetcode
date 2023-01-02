class Solution {
  struct edge {
    int index, weight;
    edge(int i, int w) : index(i), weight(w) {}
    friend bool operator<(const edge &e1, const edge &e2) {
      return e1.weight > e2.weight;
    }
  };

  int dijkstra(int n, vector<vector<edge>> &adj, int start, int threshold) {
    vector<int> d(n, INT_MAX);
    vector<bool> s(n, false);
    priority_queue<edge> pq;

    for (auto &p : adj[start]) {
      d[p.index] = p.weight;
      pq.push(p);
    }

    s[start] = true;
    for (int k = 1; k < n; k++) {
      while (!pq.empty() && s[pq.top().index]) pq.pop();
      if (pq.empty()) break;
      auto e = pq.top();
      pq.pop();
      s[e.index] = true;
      for (auto &p : adj[e.index])
        if (!s[p.index] && d[e.index] + p.weight < d[p.index]) {
          d[p.index] = d[e.index] + p.weight;
          pq.push({p.index, d[p.index]});
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) count += d[i] <= threshold;
    return count;
  }

public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector<vector<edge>> adj(n, vector<edge>());
    for (auto &p : edges) {
      adj[p[0]].push_back({p[1], p[2]});
      adj[p[1]].push_back({p[0], p[2]});
    }

    int res = -1;
    for (int i = 0, mini = INT_MAX; i < n; i++) {
      int tmp = dijkstra(n, adj, i, distanceThreshold);
      if (tmp <= mini) {
        mini = tmp;
        res = i;
      }
    }
    return res;
  }
};
