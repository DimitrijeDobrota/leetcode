class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if (color[i]) continue;
            stack<int> st;
            st.push(i), color[i] = 1;
            while (!st.empty()) {
                int root = st.top();
                st.pop();
                for (int c : graph[root]) {
                    if (color[root] == color[c]) return false;
                    if (!color[c]) {
                        st.push(c);
                        color[c] = -color[root];
                    }
                }
            }
        }
        return true;
    }
};
