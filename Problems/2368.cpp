class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    unordered_set<int> rest(restricted.begin(), restricted.end());
    vector<vector<int>> adj(n, vector<int>());

    for (auto &p : edges) {
      if (rest.count(p[0]) || rest.count(p[1])) continue;
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]);
    }

    int res = 0;
    stack<int> st;
    vector<bool> visited(n, false);
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {
      int root = st.top();
      st.pop();
      res++;
      for (int c : adj[root])
        if (!visited[c]) {
          st.push(c);
          visited[c] = true;
        }
    }
    return res;
  }
};
