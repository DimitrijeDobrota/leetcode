class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> adj(n + 1, vector<int>());
    for (auto &p : dislikes) {
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]);
    }

    stack<int> st;
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
      if (color[i] != -1) continue;
      color[i] = 0;
      st.push(i);
      while (!st.empty()) {
        int root = st.top();
        st.pop();
        for (int child : adj[root]) {
          if (color[child] == color[root]) return false;
          if (color[child] == -1) {
            color[child] = !color[root];
            st.push(child);
          }
        }
      }
    }
    return true;
  }
};
