class Solution {
  public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> anc(n, vector<int>());

        for (auto &p : edges)
            adj[p[0]].push_back(p[1]);
        for (int i = 0; i < n; i++) {
            stack<int> st;
            st.push(i);
            while (!st.empty()) {
                int root = st.top();
                st.pop();
                for (int c : adj[root]) {
                    if (!anc[c].empty() && anc[c].back() == i) continue;
                    anc[c].push_back(i);
                    st.push(c);
                }
            }
        }

        return anc;
    }
};
