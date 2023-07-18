class LRUCache {
  unordered_map<int, pair<int, int>> um;
  queue<pair<int, int>> q;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = um.find(key);
    if (it == um.end()) return -1;
    q.push({key, ++it->second.first});
    return it->second.second;
  }

  void put(int key, int value) {
    auto it = um.find(key);
    if (it != um.end()) {
      q.push({key, ++it->second.first});
      it->second.second = value;
      return;
    }

    if (um.size() == capacity) {
      while (true) {
        auto [key, time] = q.front();
        q.pop();
        if (um[key].first == time) {
          um.erase(key);
          break;
        }
      }
    }
    q.push({key, 0});
    um[key] = {0, value};
  }
};
