class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<unordered_set<int>> adj(n, unordered_set<int>());
    for (auto &p : roads) {
      adj[p[0]].insert(p[1]);
      adj[p[1]].insert(p[0]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        res = max(res, (int)(adj[i].size() + adj[j].size() - adj[i].count(j)));

    return res;
  }
};
