class Solution {
    static int getTime(int steps, int time, int change) {
        int res = 0;

        while (--steps) {
            res += time;
            if ((res / change) % 2 == 0) continue;
            res = (res / change + 1) * change;
        }

        return res + time;
    }

  public:
    int secondMinimum(int n, const vector<vector<int>> &edges, int time, int change) const {
        vector<vector<int>> adj(n + 1);
        vector<int> steps(n + 1, 100001);

        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(1);

        for (int step = 0; !q.empty() && step <= steps[n] + 1; step++) {
            for (int k = q.size(); k > 0; k--) {
                const int root = q.front();
                q.pop();

                if (step == steps[root] || step > steps[root] + 1) continue;
                steps[root] = min(steps[root], step);

                if (root == n && step > steps[n]) return getTime(step, time, change);
                for (const auto n : adj[root])
                    q.push(n);
            }
        }

        return getTime(steps[n] + 2, time, change);
    }
};
