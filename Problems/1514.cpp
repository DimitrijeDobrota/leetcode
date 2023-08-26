class Solution {
    typedef tuple<double, int> edge;

  public:
    double maxProbability(int n, const vector<vector<int>> &edges, const vector<double> &succProb, int start,
                          int end) {
        vector<vector<edge>> adj(n);
        vector<bool> visited(n, false);
        vector<double> dist(n, 0);
        priority_queue<edge> pq;

        for (int i = 0; i < succProb.size(); i++) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        pq.push({dist[start] = 1.0, start});
        while (n && !pq.empty()) {
            auto [w, dest] = pq.top();
            pq.pop();
            if (visited[dest]) continue;
            if (dest == end) return w;
            visited[dest] = true;
            for (const auto &[pw, pd] : adj[dest]) {
                if (!visited[pd] && dist[dest] * pw > dist[pd]) {
                    dist[pd] = dist[dest] * pw;
                    pq.push({dist[pd], pd});
                }
            }
            n--;
        }

        return 0;
    }
};
