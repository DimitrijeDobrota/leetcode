class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<unordered_map<int, int>> dp(n);
    vector<vector<int>> adj(n);
    vector<int> count(n, 0);

    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      count[edge[1]]++;
    }

    queue<int> q;
    stack<int> st;

    for (int i = 0; i < n; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int root = q.front();
      q.pop();
      st.push(root);
      for (int child : adj[root]) {
        if (--count[child]) continue;
        q.push(child);
      }
    }

    for (int i = 0; i < n; i++)
      if (count[i]) return -1;

    int res = 0;
    while (!st.empty()) {
      int root = st.top();
      st.pop();
      for (int child : adj[root]) {
        for (auto [color, count] : dp[child]) {
          dp[root][color] = max(dp[root][color], count);
        }
      }
      res = max(res, ++dp[root][colors[root]]);
    }
    return res;
  }
};
