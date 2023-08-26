class Solution {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> distance, parent;

    void distance_parent(int start) {
        stack<pair<int, int>> st;
        st.push({start, 0});
        parent[start] = 0;
        while (!st.empty()) {
            int p = st.top().first;
            int d = st.top().second;
            st.pop();
            distance[p] = d;
            for (int c : adj[p])
                if (distance[c] == -1) {
                    parent[c] = p;
                    st.push({c, d + 1});
                }
        }
    }

    int profit(int start, vector<int> &amount) {
        stack<pair<int, int>> st;
        st.push({start, 0});

        int maxi = INT_MIN;
        while (!st.empty()) {
            int count = 0;
            int root = st.top().first;
            int value = st.top().second + amount[root];
            st.pop();

            visited[root] = true;
            for (int c : adj[root])
                if (!visited[c]) {
                    count++;
                    st.push({c, value});
                }
            if (!count) maxi = max(value, maxi);
        }

        return maxi;
    }

  public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        int size = amount.size();
        adj.resize(size, vector<int>());
        distance.resize(size, -1);
        parent.resize(size, -1);
        visited.resize(size, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        distance_parent(0);

        for (int current = bob, bob_distance = 0; current; bob_distance++) {
            if (distance[current] > bob_distance)
                amount[current] = 0;
            else if (distance[current] == bob_distance)
                amount[current] /= 2;
            current = parent[current];
        }

        return profit(0, amount);
    }
};
