class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 0) return {};
        if (n == 1) return {0};
        if (n == 2) return {0, 1};

        vector<set<int>> adj(n);
        vector<int> count(n);

        for (auto &e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
            count[e[0]]++;
            count[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (count[i] == 1) q.push(i);

        vector<int> res;
        while (!q.empty()) {
            res.clear();
            for (int k = q.size(); k > 0; k--) {
                int c = q.front();
                q.pop();
                res.push_back(c);
                for (int n : adj[c]) {
                    if (--count[n] == 1) q.push(n);
                }
            }
        }

        return res;
    }
};
