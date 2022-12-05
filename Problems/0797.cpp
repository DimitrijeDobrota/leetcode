class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();

    vector<vector<int>> res;
    unordered_set<int> visited;
    vector<int> path;
    stack<int> st;

    st.push(0);
    while (!st.empty()) {
      int root = st.top();
      st.pop();

      if (root == n - 1) {
        path.push_back(root);
        res.push_back(path);
        path.pop_back();
        continue;
      }

      if (visited.count(root)) {
        visited.erase(root);
        path.pop_back();
        continue;
      }

      path.push_back(root);
      visited.insert(root);
      st.push(root);

      for (int n : graph[root])
        if (!visited.count(n)) st.push(n);
    }

    return res;
  }
};
