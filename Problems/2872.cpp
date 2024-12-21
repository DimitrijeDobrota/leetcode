class Solution {
  public:
    int maxKDivisibleComponents(int n, const vector<vector<int>> &edges, const vector<int> &values,
                                int k) const {
        if (n < 2) return 1;

        vector<long long> lvalues(begin(values), end(values));
        vector<vector<int>> adj(n);
        vector<int> count(n);

        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            count[e[0]]++;
            count[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (count[i] != 1) continue;
            q.push(i);
        }

        int res = 0;
        while (!q.empty()) {
            const auto crnt = q.front();
            q.pop();
            count[crnt]--;

            long long add = 0;
            if (lvalues[crnt] % k == 0)
                res++;
            else
                add = lvalues[crnt];

            for (const auto next : adj[crnt]) {
                if (count[next] == 0) continue;

                lvalues[next] += add;
                if (--count[next] == 1) {
                    q.push(next);
                }
            }
        }

        return res;
    }
};
