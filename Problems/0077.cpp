// Recursive solution
class Solution {
  vector<int> crnt;
  vector<vector<int>> res;
  void rec(int s, int n, int k) {
    if (s > n + 1) return;
    if (!k) {
      res.push_back(crnt);
      return;
    }

    crnt.push_back(s);
    rec(s + 1, n, k - 1);
    crnt.pop_back();
    rec(s + 1, n, k);
  }

public:
  vector<vector<int>> combine(int n, int k) {
    rec(1, n, k);
    return res;
  }
};

// Iterative solution
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> iter;
    iter.reserve(k);
    for (int mask = (1 << k) - 1; mask < 1 << n; mask++) {
      if (__builtin_popcount(mask) != k) continue;

      for (int crnt = mask, idx; crnt; crnt ^= 1 << (idx - 1)) {
        idx = __builtin_ffs(crnt);
        iter.push_back(idx);
      }
      res.push_back(iter);
      iter.clear();
    }
    return res;
  }
};

// Improved iterative solution with bit twiddling
class Solution {
  int twiddle(int v) {
    int t = v | (v - 1);
    int w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    return w;
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> iter;
    iter.reserve(k);
    for (int mask = (1 << k) - 1; mask < 1 << n; mask = twiddle(mask)) {
      for (int crnt = mask, idx; crnt; crnt ^= 1 << (idx - 1)) {
        idx = __builtin_ffs(crnt);
        iter.push_back(idx);
      }
      res.push_back(iter);
      iter.clear();
    }
    return res;
  }
};
