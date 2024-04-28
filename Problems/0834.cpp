class Solution {
  public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        vector<int> res(n), count(n, 1);

        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        using record_t = tuple<int, int>;
        stack<record_t> st;

        for (st.emplace(-1, 0); !st.empty();) {
            if (get<1>(st.top()) != -1) {
                const auto [parent, root] = st.top();
                st.emplace(-1, -1);
                for (const auto next : adj[root]) {
                    if (next == parent) continue;
                    st.emplace(root, next);
                }
                continue;
            }

            st.pop();
            const auto [parent, root] = st.top();
            st.pop();

            for (const auto next : adj[root]) {
                if (next == parent) continue;
                count[root] += count[next];
                res[root] += res[next] + count[next];
            }
        }

        for (st.emplace(-1, 0); !st.empty();) {
            const auto [parent, root] = st.top();
            st.pop();

            for (const auto next : adj[root]) {
                if (next == parent) continue;
                res[next] = res[root] - count[next] + (n - count[next]);
                st.emplace(root, next);
            }
        }

        return res;
    }
};
