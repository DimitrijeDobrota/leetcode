class Solution {
  const int SIZE = 26 * 5;

  int hash(const string &st) {
    static int index = 0;
    static unordered_map<string, int> um;
    if (!um.count(st)) um[st] = index++;
    return um[st];
  }

  double dfs(vector<vector<pair<int, double>>> &adj, int start, int goal) {
    stack<pair<int, double>> st;
    vector<bool> visited(SIZE, false);

    st.push({start, 1});
    visited[start] = true;
    while (!st.empty()) {
      auto [root, value] = st.top();
      st.pop();
      if (root == goal) return value;
      visited[root] = true;
      for (auto &v : adj[root])
        if (!visited[v.first]) st.push({v.first, value * v.second});
    }
    return -1;
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    vector<vector<pair<int, double>>> adj(SIZE, vector<pair<int, double>>());
    for (int i = 0; i < values.size(); i++) {
      adj[hash(equations[i][0])].push_back({hash(equations[i][1]), values[i]});
      adj[hash(equations[i][1])].push_back(
          {hash(equations[i][0]), 1 / values[i]});
    }

    vector<double> res(queries.size(), -1);
    for (int i = 0; i < queries.size(); i++) {
      int start = hash(queries[i][0]), goal = hash(queries[i][1]);
      if (adj[start].empty() || adj[goal].empty()) continue;
      res[i] = dfs(adj, start, goal);
    }
    return res;
  }
};
