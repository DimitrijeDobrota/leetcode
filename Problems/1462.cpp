// DFS
class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<vector<int>> adj(numCourses);
    vector<unordered_set<int>> pre(numCourses);

    for (auto &p : prerequisites) adj[p[0]].push_back(p[1]);

    for (int i = 0; i < numCourses; i++) {
      unordered_set<int> visited;
      stack<int> st;
      st.push(i);
      visited.insert(i);
      while (!st.empty()) {
        int crnt = st.top();
        st.pop();
        for (int &c : adj[crnt]) {
          if (visited.count(c)) continue;
          visited.insert(c);
          pre[c].insert(i);
          st.push(c);
        }
      }
    }

    vector<bool> res;
    for (auto &p : queries) res.push_back(pre[p[1]].count(p[0]));
    return res;
  }
};

// Topological sort with dependency propagation
class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<unordered_set<int>> pre(numCourses);
    vector<vector<int>> adj(numCourses);
    vector<int> count(numCourses);

    for (auto &p : prerequisites) {
      adj[p[0]].push_back(p[1]);
      count[p[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (!count[i]) q.push(i);

    while (!q.empty()) {
      int crnt = q.front();
      q.pop();
      for (int &c : adj[crnt]) {
        pre[c].insert(crnt);
        pre[c].insert(pre[crnt].begin(), pre[crnt].end());
        if (!--count[c]) q.push(c);
      }
    }

    vector<bool> res;
    for (auto &p : queries) res.push_back(pre[p[1]].count(p[0]));
    return res;
  }
};

// Topological sort using bitseclass Solution {
public:
vector<bool> checkIfPrerequisite(int numCourses,
                                 vector<vector<int>> &prerequisites,
                                 vector<vector<int>> &queries) {
  vector<bitset<100>> pre(numCourses);
  vector<vector<int>> adj(numCourses);
  vector<int> count(numCourses);

  for (auto &p : prerequisites) {
    adj[p[0]].push_back(p[1]);
    count[p[1]]++;
  }

  queue<int> q;
  for (int i = 0; i < numCourses; i++)
    if (!count[i]) q.push(i);

  while (!q.empty()) {
    int crnt = q.front();
    q.pop();
    for (int &c : adj[crnt]) {
      pre[c].set(crnt);
      pre[c] |= pre[crnt];
      if (!--count[c]) q.push(c);
    }
  }

  vector<bool> res;
  for (auto &p : queries) res.push_back(pre[p[1]][p[0]]);
  return res;
}
}
;
