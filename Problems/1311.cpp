class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &adj, int id,
                                        int level) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(id);
    visited[id] = true;
    for (int lvl = 0; lvl != level; lvl++) {
      for (int k = q.size(); k > 0; k--) {
        int id = q.front();
        q.pop();
        for (int c : adj[id]) {
          if (!visited[c]) {
            visited[c] = true;
            q.push(c);
          }
        }
      }
    }

    unordered_map<string, int> freq;
    vector<pair<int, string>> vec;
    vector<string> res;

    for (; !q.empty(); q.pop())
      for (auto &st : watchedVideos[q.front()]) freq[st]++;

    for (auto &[k, v] : freq) vec.push_back({v, k});
    sort(vec.begin(), vec.end());
    for (auto &[_, title] : vec) res.push_back(title);
    return res;
  }
};
