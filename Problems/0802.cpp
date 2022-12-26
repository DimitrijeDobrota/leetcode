class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> res;
    vector<bool> visited(n, false);
    vector<bool> safe(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      st.push(i);
      while (!st.empty()) {
        int root = st.top();
        st.pop();
        if (root == -1) {
          root = st.top();
          st.pop();
          bool s = true;
          for (int c : graph[root])
            if (!safe[c]) {
              s = false;
              break;
            }
          safe[root] = s;
          continue;
        }
        if (visited[root]) continue;
        visited[root] = true;
        st.push(root);
        st.push(-1);
        for (int c : graph[root])
          if (!visited[c]) st.push(c);
      }
    }
    for (int i = 0; i < n; i++)
      if (safe[i]) res.push_back(i);
    return res;
  }
};
