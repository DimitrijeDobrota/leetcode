class Solution {
  typedef vector<vector<int>> ADJ;

public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
    vector<ADJ> adj(2, ADJ(n));
    queue<pair<int, int>> q;

    for (auto &e : redEdges) adj[0][e[0]].push_back(e[1]);
    for (auto &e : blueEdges) adj[1][e[0]].push_back(e[1]);

    q.push({0, 0});
    q.push({0, 1});
    dist[0][0] = dist[1][0] = 0;
    while (!q.empty()) {
      auto [crnt, col] = q.front();
      q.pop();
      for (int c : adj[!col][crnt]) {
        if (dist[!col][c] != INT_MAX) continue;
        dist[!col][c] = dist[col][crnt] + 1;
        q.push({c, !col});
      }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = min(dist[0][i], dist[1][i]);
      if (res[i] == INT_MAX) res[i] = -1;
    }

    return res;
  }
};
