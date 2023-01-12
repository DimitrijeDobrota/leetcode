class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> count(n, vector<int>(26, 0));
    vector<int> res(n);

    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    stack<pair<int, int>> st;
    st.push({0, -1});
    while (!st.empty()) {
      if (st.top().first == -1) {
        st.pop();

        auto [crnt, par] = st.top();
        st.pop();

        for (int c : adj[crnt]) {
          if (c == par) continue;
          for (int i = 0; i < 26; i++) count[crnt][i] += count[c][i];
        }

        res[crnt] = ++count[crnt][labels[crnt] - 'a'];
        continue;
      }

      auto [crnt, par] = st.top();
      st.push({-1, -1});

      for (int c : adj[crnt]) {
        if (c == par) continue;
        st.push({c, crnt});
      }
    }

    return res;
  }
};
