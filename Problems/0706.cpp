class MyHashMap {
  const int mod = 9973;

  vector<vector<pair<int, int>>> hm;
  int hash(int key) { return key % mod; }

  int &find(int key) {
    static int err = -1;
    for (auto &[k, v] : hm[hash(key)])
      if (k == key) return v;
    return err;
  }

public:
  MyHashMap() : hm(mod) {}
  void put(int key, int value) {
    int &loc = find(key);
    if (loc == -1)
      hm[hash(key)].push_back({key, value});
    else
      loc = value;
  }
  int get(int key) { return find(key); }
  void remove(int key) {
    vector<pair<int, int>> &row = hm[hash(key)];
    for (int i = 0; i < row.size(); i++)
      if (row[i].first == key) {
        row.erase(row.begin() + i);
        break;
      }
  }
};
