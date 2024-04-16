class Solution {
  public:
    vector<int> countPairsOfConnectableServers(const vector<vector<int>> &edges,
                                               const int signalSpeed) const {
        const int n = size(edges) + 1;
        vector<vector<pair<int, int>>> adj(n);

        for (const auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        static int cnt[1001], res[1001];
        stack<tuple<int, int, int>> st;

        memset(res, 0x00, n * sizeof(*res));
        for (int i = 0; i < n; i++) {
            memset(cnt, 0x00, sizeof(cnt));
            for (int j = 0; j < size(adj[i]); j++) {
                st.emplace(i, adj[i][j].first, adj[i][j].second);

                while (!st.empty()) {
                    const auto [p, c, t] = st.top();
                    st.pop();
                    if (t % signalSpeed == 0) cnt[j]++;
                    for (const auto [n, w] : adj[c]) {
                        if (n == p) continue;
                        st.emplace(c, n, t + w);
                    }
                }

                for (int k = 0; k < j; k++)
                    res[i] += cnt[j] * cnt[k];
            }
        }

        return vector<int>(res, res + n);
    }
};
