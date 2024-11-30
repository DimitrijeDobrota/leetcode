class Solution {
  public:
    vector<vector<int>> validArrangement(const vector<vector<int>> &pairs) const {
        unordered_map<int, int> in, out, count;
        unordered_map<int, vector<int>> adj;

        for (const auto &p : pairs) {
            adj[p[0]].push_back(p[1]);
            out[p[0]]++, in[p[1]]++;
        }

        int start = pairs[0][0];
        for (const auto &[v, _] : adj) {
            if (out[v] - in[v] != 1) continue;
            start = v;
            break;
        }

        stack<int> st;
        vector<int> res;
        for (st.push(start); !st.empty();) {
            const int crnt = st.top();

            if (count[crnt] != size(adj[crnt])) {
                st.push(adj[crnt][count[crnt]++]);
            } else {
                res.push_back(crnt);
                st.pop();
            }
        }

        vector<vector<int>> pair_res;
        for (int i = size(res) - 2; i >= 0; i--) {
            pair_res.push_back({res[i + 1], res[i]});
        }

        return pair_res;
    }
};
