class Solution {
  public:
    vector<int> sortItems(int n, int m, vector<int> &group, const vector<vector<int>> &beforeItems) {
        for (int &g : group)
            if (g == -1) g = m++;

        vector<unordered_set<int>> gadj(m);
        vector<vector<int>> adj(n), ordered(m);
        vector<int> gcount(m, 0), count(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            count[i] = beforeItems[i].size();
            for (int elem : beforeItems[i]) {
                adj[elem].push_back(i);
                if (group[elem] == group[i]) continue;
                if (gadj[group[elem]].count(group[i])) continue;
                gadj[group[elem]].insert(group[i]);
                gcount[group[i]]++;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (!count[i]) q.push(i);
        while (!q.empty()) {
            const int root = q.front();
            ordered[group[root]].push_back(root);
            for (int next : adj[q.front()]) {
                if (!--count[next]) q.push(next);
            }
            q.pop();
            cnt++;
        }

        if (cnt != n) return {};

        vector<int> res;
        for (int i = 0; i < m; i++)
            if (!gcount[i]) q.push(i);
        while (!q.empty()) {
            const int root = q.front();
            res.insert(res.end(), ordered[root].begin(), ordered[root].end());
            for (int next : gadj[q.front()]) {
                if (!--gcount[next]) q.push(next);
            }
            q.pop();
        }

        return res.size() == n ? res : vector<int>();
    }
};
