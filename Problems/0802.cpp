class Solution {
public:
  vector<int> eventualSafeNodes(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false), safe(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      st.push(i);
      while (!st.empty()) {
        int root = st.top();
        if (root == -1) {
          st.pop();
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
        if (visited[root]) {
          st.pop();
          continue;
        };
        visited[root] = true;
        st.push(-1);
        for (int c : graph[root])
          if (!visited[c]) st.push(c);
      }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
      if (safe[i]) res.push_back(i);
    return res;
  }
};

// Cleaner code, more memory
class Solution {
  int safe[100001] = {0}, count[10001] = {0};

public:
  vector<int> eventualSafeNodes(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      count[i] += graph[i].size();
      for (int node : graph[i]) adj[node].push_back(i);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int root = q.front();
      q.pop();
      safe[root] = true;

      for (auto node : adj[root])
        if (!--count[node]) q.push(node);
    }

    vector<int> res;
    for (int i = 0; i < graph.size(); i++)
      if (safe[i]) res.push_back(i);
    return res;
  }
};
