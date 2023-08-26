class Solution {
public:
  int largestCombination(const vector<int> &candidates) {
    int res = 0, maxi = *max_element(begin(candidates), end(candidates));
    for (int mask = 1, cnt = 0; mask <= maxi; mask <<= 1, cnt = 0) {
      for (int n : candidates) cnt += (n & mask) > 0;
      res = max(res, cnt);
    }
    return res;
  }
};
