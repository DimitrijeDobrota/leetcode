class Solution {
  const string len(const string &s, int a, int b) {
    while (a >= 0 && b < s.size() && s[a] == s[b]) a--, b++;
    return s.substr(a + 1, b - a - 1);
  }

public:
  string longestPalindrome(string s) {
    string res = "", t;
    s.push_back(' ');
    for (int i = 0; i < s.size(); i++) {
      t = len(s, i, i);
      if (t.size() > res.size()) res = t;
      if (s[i] != s[i + 1]) continue;
      t = len(s, i, i + 1);
      if (t.size() > res.size()) res = t;
    }
    return res;
  }
};
