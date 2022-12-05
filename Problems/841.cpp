class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_set<int> us;
    queue<int> q;

    q.push(0);
    us.insert(0);
    while (!q.empty()) {
      int room = q.front();
      q.pop();
      for (int key : rooms[room]) {
        if (!us.count(key)) {
          us.insert(key);
          q.push(key);
        }
      }
    }
    return us.size() == rooms.size();
  }
};
