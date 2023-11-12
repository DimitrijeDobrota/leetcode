class Solution {
  public:
    int numBusesToDestination(const vector<vector<int>> &routes, int source, int target) const {
        if (source == target) return 0;

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < routes.size(); i++) {
            for (const int n : routes[i])
                adj[n].push_back(i);
        }

        if (!adj.count(target)) return -1;

        unordered_set<int> used;
        queue<int> q;

        q.push(source);
        for (int lvl = 1; !q.empty(); lvl++) {
            for (int k = q.size(); k > 0; k--) {
                const int crnt = q.front();
                q.pop();
                for (const int r : adj[crnt]) {
                    if (used.count(-r)) continue;
                    used.insert(-r);
                    for (const int v : routes[r]) {
                        if (used.count(v)) continue;
                        if (v == target) return lvl;
                        used.insert(v);
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }
};
