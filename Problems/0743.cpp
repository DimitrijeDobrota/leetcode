class Solution {
    typedef pair<int, int> edge;

  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<edge>> adj(n + 1, vector<edge>());
        for (auto &p : times)
            adj[p[0]].push_back({p[2], p[1]});

        priority_queue<edge, vector<edge>, greater<edge>> st;
        unordered_set<int> us;

        int time = 0;
        st.push({0, k});
        while (!st.empty()) {
            auto [t, root] = st.top();
            st.pop();
            if (us.count(root)) continue;
            time = t;
            us.insert(root);
            for (auto &[time, dest] : adj[root])
                if (!us.count(dest)) st.push({t + time, dest});
        }
        return us.size() == n ? time : -1;
    }
};
