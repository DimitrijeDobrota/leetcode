class Solution {
  struct edge {
    int dest;
    double w;
    edge(int d, double w) : dest(d), w(w) {}
    friend bool operator<(const edge &e1, const edge &e2) {
      return e1.w < e2.w;
    }
  };

public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    vector<vector<edge>> adj(n);
    vector<int> visited(n, false);
    vector<double> dist(n, 0);
    priority_queue<edge> pq;

    for (int i = 0; i < succProb.size(); i++) {
      adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
      adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    pq.push({start, dist[start] = 1.0});
    for (int k = 0; k < n; k++) {
      while (!pq.empty() && visited[pq.top().dest]) pq.pop();
      if (pq.empty()) break;
      edge c = pq.top();
      pq.pop();
      if (c.dest == end) return c.w;
      visited[c.dest] = true;
      for (edge &p : adj[c.dest])
        if (!visited[p.dest] && dist[c.dest] * p.w > dist[p.dest]) {
          dist[p.dest] = dist[c.dest] * p.w;
          pq.push({p.dest, dist[p.dest]});
        }
    }

    return 0;
  }
};
