class Solution {
public:
  int minSteps(const string &s, const string &t) {
    int res = 0, count[27] = {0};
    for (int i = 0; i < s.size(); i++) {
      count[s[i] & 0x1F]++;
      count[t[i] & 0x1F]--;
    }
    for (int i = 1; i < 27; i++) {
      if (count[i] > 0) res += count[i];
    }
    return res;
  }
};
