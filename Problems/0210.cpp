class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> count(n, 0);
        vector<int> res;
        int num = 0;

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            count[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!count[i]) q.push(i);

        while (!q.empty()) {
            int root = q.front();
            q.pop();
            res.push_back(root);
            n--;
            for (int c : adj[root])
                if (!--count[c]) q.push(c);
        }
        return n == 0 ? res : vector<int>();
    }
};
