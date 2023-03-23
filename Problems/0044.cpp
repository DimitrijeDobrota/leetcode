class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0, j = 0, n = s.size(), m = p.size();
    int last = -1, star = -1;
    while (i < n) {
      if (j < m && (s[i] == p[j] || p[j] == '?'))
        i++, j++;
      else if (j < m && p[j] == '*') {
        star = j++;
        last = i;
      } else if (star != -1) {
        j = star + 1;
        i = ++last;
      } else
        return false;
    }
    while (p[j] == '*' && j < m) j++;
    return j == m;
  }
};
