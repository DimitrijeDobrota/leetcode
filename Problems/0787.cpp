class Solution {
    struct edge {
        int d, w, s;
        edge(int d, int w, int s = -1) : d(d), w(w), s(s) {}
        friend bool operator<(const edge &e1, const edge &e2) { return e1.w > e2.w; }
    };

  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<vector<edge>> adj(n);
        for (auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        vector<int> stop(n, INT_MAX);
        priority_queue<edge> pq;

        pq.push({src, 0, 0});
        while (!pq.empty()) {
            auto [d, w, s] = pq.top();
            pq.pop();
            if (s > stop[d] || s > k + 1) continue;

            stop[d] = s;
            if (d == dst) return w;
            for (auto [d1, w1, _] : adj[d])
                pq.push({d1, w + w1, s + 1});
        }
        return -1;
    }
};
