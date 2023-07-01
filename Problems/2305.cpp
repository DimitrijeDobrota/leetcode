class Solution {
  vector<int> children = vector(8, 0);
  int res = INT_MAX;

  void rec(const vector<int> &cookies, vector<int> &children, int k, int cur,
           int zero, int maxi = 0) {
    if (cookies.size() - cur < zero) return;
    if (cur >= cookies.size()) {
      res = min(res, maxi);
      return;
    }

    for (int i = 0; i < k; i++) {
      zero -= children[i] == 0 ? 1 : 0;
      children[i] += cookies[cur];
      rec(cookies, children, k, cur + 1, zero, max(maxi, children[i]));
      children[i] -= cookies[cur];
      zero += children[i] == 0 ? 1 : 0;
    }
  }

public:
  int distributeCookies(const vector<int> &cookies, int k) {
    vector<int> children = vector(k, 0);
    rec(cookies, children, k, 0, k);
    return res;
  }
};
