class Solution {
  public:
    int minReorder(int n, vector<vector<int>> &connections) {
        unordered_set<string> us;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n, vector<int>());

        for (auto &e : connections) {
            us.insert(to_string(e[0]) + " " + to_string(e[1]));
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;

        stack<int> st;
        st.push(0);
        visited[0] = true;
        while (!st.empty()) {
            int root = st.top();
            st.pop();
            for (auto c : adj[root])
                if (!visited[c]) {
                    if (!us.count(to_string(c) + " " + to_string(root))) res++;
                    visited[c] = true;
                    st.push(c);
                }
        }
        return res;
    }
};
