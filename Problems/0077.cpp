class Solution {
  vector<int> crnt;
  vector<vector<int>> res;
  void rec(int s, int n, int k) {
    if (!k) {
      res.push_back(crnt);
      return;
    }
    for (int i = s; i <= n; i++) {
      crnt.push_back(i);
      rec(i + 1, n, k - 1);
      crnt.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    rec(1, n, k);
    return res;
  }
};
