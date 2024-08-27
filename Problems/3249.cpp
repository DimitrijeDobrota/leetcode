class Solution {
  public:
    int countGoodNodes(const vector<vector<int>> &edges) const {
        static int count[100001];
        const int n = size(edges) + 1;
        vector<vector<int>> adj(n);
        stack<pair<int, int>> st;
        int res = 0;

        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        st.emplace(0, -1);
        memset(count, 0x00, sizeof(count));
        while (!st.empty()) {
            if (st.top().first != -1) {
                const auto [root, parent] = st.top();
                st.emplace(-1, -1);

                for (const int next : adj[root]) {
                    if (next == parent) continue;
                    st.emplace(next, root);
                }

                continue;
            }

            st.pop();
            const auto [root, parent] = st.top();
            st.pop();

            int cnt = 1;
            int goal = -1;
            bool good = true;

            for (int i = 0; i < size(adj[root]); i++) {
                const int next = adj[root][i];
                if (next == parent) continue;
                if (goal == -1)
                    goal = count[next];
                else if (count[next] != goal)
                    good = false;
                cnt += count[next];
            }

            if (good) res++;

            count[root] = cnt;
        }

        return res;
    }
};
