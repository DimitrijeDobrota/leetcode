class Solution {
public:
  int minJumps(vector<int> &arr) {
    if (arr.size() < 2) return 0;
    if (arr.front() == arr.back()) return 1;

    unordered_map<int, vector<int>> um;
    unordered_set<int> visited;
    int n = arr.size();

    for (int i = 0; i < n; i++) um[arr[i]].push_back(i);

    queue<int> q;
    q.push(0);
    visited.insert(0);
    for (int lvl = 0; !q.empty(); lvl++) {
      for (int k = q.size(); k > 0; k--) {
        int crnt = q.front();
        q.pop();

        if (crnt == n - 1) return lvl;

        if (crnt + 1 < n && !visited.count(crnt + 1)) {
          visited.insert(crnt + 1);
          q.push(crnt + 1);
        }

        if (crnt - 1 >= 0 && !visited.count(crnt - 1)) {
          visited.insert(crnt - 1);
          q.push(crnt - 1);
        }

        for (int index : um[arr[crnt]]) {
          if (!visited.count(index)) {
            visited.insert(index);
            q.push(index);
          }
        }

        um[arr[crnt]].clear();
      }
    }
    return -1;
  }
};
