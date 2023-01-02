class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    vector<vector<int>> adj(bombs.size());
    for (int i = 0; i < bombs.size(); i++) {
      for (int j = i + 1; j < bombs.size(); j++) {
        double dist = sqrt(pow(bombs[i][0] - bombs[j][0], 2) +
                           pow(bombs[i][1] - bombs[j][1], 2));
        if (dist <= bombs[i][2]) adj[i].push_back(j);
        if (dist <= bombs[j][2]) adj[j].push_back(i);
      }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < bombs.size(); i++) {
      vector<bool> visited(bombs.size(), false);
      int count = 0;
      stack<int> st;
      st.push(i);
      visited[i] = true;
      while (!st.empty()) {
        int root = st.top();
        st.pop();
        count++;
        for (int c : adj[root])
          if (!visited[c]) {
            visited[c] = true;
            st.push(c);
          }
      }
      maxi = max(maxi, count);
    }

    return maxi;
  }
};
