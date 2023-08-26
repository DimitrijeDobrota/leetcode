class Solution {
  public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<vector<int>> adj(n, vector<int>()), count(n, vector<int>(26, 0));
        vector<bool> visited(n, false);
        vector<int> res(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int crnt = st.top();
            if (visited[crnt]) {
                st.pop();

                for (int c : adj[crnt]) {
                    if (visited[c]) continue;
                    for (int i = 0; i < 26; i++)
                        count[crnt][i] += count[c][i];
                }
                res[crnt] = ++count[crnt][labels[crnt] - 'a'];
                visited[crnt] = false;
                continue;
            }

            visited[crnt] = true;
            for (int c : adj[crnt]) {
                if (visited[c]) continue;
                st.push(c);
            }
        }

        return res;
    }
};
