class Solution {
  public:
    int longestCycle(vector<int> &edges) {
        int n = edges.size(), res = -1;
        vector<int> count(n, 0);
        for (int edge : edges)
            if (edge != -1) count[edge]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!count[i]) q.push(i);

        while (!q.empty()) {
            int root = q.front();
            q.pop();
            if (edges[root] == -1) continue;
            if (--count[edges[root]] == 0) q.push(edges[root]);
        }

        for (int i = 0; i < n; i++) {
            if (!count[i]) continue;
            int k = i, num = 1;
            while (edges[k] != i) {
                count[k] = 0;
                k = edges[k];
                num++;
            }
            res = max(res, num);
        }

        return res;
    }
};
