class Solution {
  public:
    int minimumTime(int n, const vector<vector<int>> &relations, const vector<int> &time) {
        vector<vector<int>> adj(n);
        vector<int> count(n, 0), wait(n, 0);

        for (const auto &relation : relations) {
            adj[relation[0] - 1].push_back(relation[1] - 1);
            count[relation[1] - 1]++;
        }

        queue<int> q;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (!count[i]) q.push(i);
        while (!q.empty()) {
            const int root = q.front();
            wait[root] += time[root];
            res = max(res, wait[root]);
            q.pop();
            for (const int next : adj[root]) {
                wait[next] = max(wait[next], wait[root]);
                if (!--count[next]) q.push(next);
            }
        }

        return res;
    }
};
