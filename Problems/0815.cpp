class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) return 0;

    unordered_map<int, vector<int>> adj;
    queue<int> q;

    for (int i = 0; i < routes.size(); i++)
      for (auto s : routes[i]) adj[s].push_back(i);
    if (!adj.count(target)) return -1;

    q.push(source);
    for (int lvl = 1; !q.empty(); lvl++) {
      for (int k = q.size(); k > 0; k--) {
        int crnt = q.front();
        q.pop();
        for (int r : adj[crnt]) {
          for (int v : routes[r]) {
            if (v == target) return lvl;
            q.push(v);
          }
          routes[r].clear();
        }
        adj[crnt].clear();
      }
    }

    return -1;
  }
};
