class Solution {
  vector<string> res;
  string crnt;

  void rec(int n, int k, char last = 'x') {
    if (res.size() == k) return;
    if (crnt.size() == n) {
      res.push_back(crnt);
      return;
    }
    crnt.push_back(' ');
    for (char c = 'a'; c <= 'c'; c++) {
      if (c == last) continue;
      crnt.back() = c;
      rec(n, k, c);
    }
    crnt.pop_back();
  }

public:
  string getHappyString(int n, int k) {
    if (k > 3 * (1 << n - 1)) return "";
    rec(n, k);
    return res.back();
  }
};
