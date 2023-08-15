// 2120. Execution of All Suffix Instructions Staying in a Grid
class Solution {
public:
  vector<int> executeInstructions(int n, const vector<int> &startPos,
                                  string s) {
    const auto valid = [n](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < n;
    };

    vector<int> res;
    res.reserve(s.size());
    for (int k = 0; k < s.size(); k++) {
      int x = startPos[0], y = startPos[1];
      for (int i = k; i < s.size(); i++) {
        if (s[i] == 'L') y--;
        if (s[i] == 'R') y++;
        if (s[i] == 'U') x--;
        if (s[i] == 'D') x++;
        if (!valid(x, y)) {
          res.push_back(i - k);
          goto next;
        }
      }
      res.push_back(s.size() - k);
    next:;
    }
    return res;
  }
};
