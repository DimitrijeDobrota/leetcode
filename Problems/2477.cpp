class Solution {
  public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> count(n, 0);
        stack<pair<int, int>> st;

        for (auto &p : roads) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        long long total = 0;
        st.push({0, -1});
        while (!st.empty()) {
            auto [root, parent] = st.top();
            st.pop();
            if (parent == -2) {
                for (int c : adj[root]) {
                    count[root] += count[c];
                    total += ceil(1.0 * count[c] / seats);
                }
                count[root]++;
                continue;
            }
            st.push({root, -2});
            for (int c : adj[root])
                if (c != parent) st.push({c, root});
        }
        return total;
    }
};
