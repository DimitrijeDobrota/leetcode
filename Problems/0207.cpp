class Solution {
  static int adj[2048][2048];

public:
  bool canFinish(int n, const vector<vector<int>> &prerequisites) {
    int count[2048] = {0}, size[2048] = {0};

    for (auto &p : prerequisites) {
      adj[p[0]][size[p[0]]++] = p[1];
      count[p[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int root = q.front();
      q.pop(), n--;
      for (int i = 0; i < size[root]; i++)
        if (!--count[adj[root][i]]) q.push(adj[root][i]);
    }

    return n == 0;
  }
};

int Solution::adj[2048][2048];
