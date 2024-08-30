class Solution {
    using edge_t = pair<int, int>;
    using adj_t = vector<vector<edge_t>>;

    void dijkstra(const adj_t &adj, vector<vector<int>> &edges, vector<vector<int>> &dist, int src, int diff,
                  int run) {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src][run] = 0;
        pq.emplace(0, src);
        while (!pq.empty()) {
            auto [currentdist, currentNode] = pq.top();
            pq.pop();

            if (currentdist > dist[currentNode][run]) continue;
            for (auto &[next, idx] : adj[currentNode]) {
                int w = edges[idx][2];

                if (w == -1) w = 1;

                if (run == 1 && edges[idx][2] == -1) {
                    int nw = diff + dist[next][0] - dist[currentNode][1];
                    if (nw > w) {
                        edges[idx][2] = w = nw;
                    }
                }

                if (dist[next][run] > dist[currentNode][run] + w) {
                    dist[next][run] = dist[currentNode][run] + w;
                    pq.emplace(dist[next][run], next);
                }
            }
        }
    }

  public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int src, int dest, int tgt) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].emplace_back(b, i);
            adj[b].emplace_back(a, i);
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[src][0] = dist[src][1] = 0;

        dijkstra(adj, edges, dist, src, 0, 0);
        int diff = tgt - dist[dest][0];
        if (diff < 0) return {};

        dijkstra(adj, edges, dist, src, diff, 1);
        if (dist[dest][1] < tgt) return {};

        for (auto &edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }
};
