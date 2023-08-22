class Solution {
  unordered_set<string> us;
  bool used[8] = {false};
  string crnt;

  void rec(const string &tiles) {
    us.insert(crnt);
    if (crnt.size() == tiles.size()) return;

    for (int i = 0; i < tiles.size(); i++) {
      if (used[i]) continue;
      used[i] = true;
      crnt.push_back(tiles[i]);
      rec(tiles);
      crnt.pop_back();
      used[i] = false;
    }
  }

public:
  int numTilePossibilities(const string tiles) {
    rec(tiles);
    return us.size() - 1;
  }
};
