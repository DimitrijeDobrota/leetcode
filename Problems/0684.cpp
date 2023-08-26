class Solution {
  public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);
        stack<int> st;
        int res = 0;

        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(-e[0]);
        }

        st.push(0);
        visited[0] = true;
        while (!st.empty()) {
            int root = st.top();
            st.pop();
            for (auto c : adj[root]) {
                int ac = abs(c);
                if (!visited[ac]) {
                    res += c > 0;
                    visited[ac] = true;
                    st.push(ac);
                }
            }
        }
        return res;
    }
};
