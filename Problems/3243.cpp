class Solution {
  public:
    vector<int> shortestDistanceAfterQueries(int n, const vector<vector<int>> &queries) const {
        vector<vector<int>> adj(n);
        static int len[501];

        len[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i - 1);
            len[i - 1] = n - i;
        }

        vector<int> res;
        queue<pair<int, int>> q;
        for (const auto query : queries) {
            for (q.emplace(query[0], len[query[1]]); !q.empty();) {
                const auto [crnt, parent] = q.front();
                q.pop();

                if (len[crnt] <= parent + 1) continue;

                len[crnt] = parent + 1;
                for (const int next : adj[crnt])
                    q.emplace(next, len[crnt]);
            }

            adj[query[1]].push_back(query[0]);
            res.push_back(len[0]);
        }

        return res;
    }
};
