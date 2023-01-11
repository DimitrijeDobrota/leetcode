class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
    vector<vector<int>> adj(n, vector<int>());
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    stack<pair<int, int>> st;
    int res = 0;

    st.push({0, -1});
    while (!st.empty()) {
      if (st.top().first == -1) {
        st.pop();

        auto [crnt, par] = st.top();
        st.pop();
        int count = 0;

        for (int c : adj[crnt]) {
          if (c == par) continue;
          count += hasApple[c];
        }

        res += count;
        hasApple[crnt] = hasApple[crnt] || count;
        continue;
      }

      auto [crnt, par] = st.top();
      st.push({-1, -1});

      for (int c : adj[crnt]) {
        if (c == par) continue;
        st.push({c, crnt});
      }
    }

    return res * 2;
  }
};
