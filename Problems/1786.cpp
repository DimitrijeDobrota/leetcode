class Solution {
    const int mod = 1000000007;

    struct edge {
        int dest, w;
        edge(int d, int w) : dest(d), w(w) {}
        friend bool operator<(const edge &e1, const edge &e2) { return e1.w > e2.w; }
    };

    vector<int> dijkstra(int n, vector<vector<edge>> &adj, int start) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<edge> pq;

        vector<int> visited(n + 1, false);
        pq.push({n, dist[n] = 0});
        for (int k = 0; k < n; k++) {
            while (!pq.empty() && visited[pq.top().dest])
                pq.pop();
            if (pq.empty()) break;
            edge c = pq.top();
            pq.pop();
            visited[c.dest] = true;
            for (edge &p : adj[c.dest])
                if (!visited[p.dest] && dist[c.dest] + p.w < dist[p.dest]) {
                    dist[p.dest] = dist[c.dest] + p.w;
                    pq.push({p.dest, dist[p.dest]});
                }
        }
        return dist;
    }

  public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges) {
        vector<vector<edge>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        vector<int> dist = dijkstra(n, adj, n);
        vector<int> dp(n + 1, 0);
        vector<int> visited(n + 1, 0);
        stack<int> st;

        int count = 0;
        st.push(1);
        while (!st.empty()) {
            int root = st.top();

            if (root == n) {
                st.pop();
                count++;
                continue;
            }

            if (root == -1) {
                st.pop();
                root = st.top();
                st.pop();
                dp[root] += count;
                continue;
            }

            dp[root] = -count;
            visited[root] = true;
            st.push(-1);
            for (auto [c, w] : adj[root])
                if (dist[root] > dist[c]) {
                    if (visited[c] && dp[c] >= 0)
                        count = (count + dp[c]) % mod;
                    else
                        st.push(c);
                }
        }

        return count;
    }
};
