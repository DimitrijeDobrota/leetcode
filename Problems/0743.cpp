class Solution {
  struct edge {
    int dest, time;
    edge(int dest, int time) : dest(dest), time(time) {}
    friend bool operator<(const edge &s1, const edge &s2) {
      return s1.time > s2.time;
    }
  };

public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<edge>> adj(n + 1, vector<edge>());
    for (auto &p : times) adj[p[0]].push_back({p[1], p[2]});

    priority_queue<edge> st;
    st.push({k, 0});
    unordered_set<int> us;
    int time = 0;
    while (!st.empty()) {
      auto [root, t] = st.top();
      st.pop();
      if (us.count(root)) continue;
      time = t;
      us.insert(root);
      for (auto &p : adj[root])
        if (!us.count(p.dest)) st.push({p.dest, t + p.time});
    }
    return us.size() == n ? time : -1;
  }
};
