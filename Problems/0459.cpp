class Solution {
public:
  bool repeatedSubstringPattern(const string &s) {
    string made;
    for (int i = 1; i <= s.size() / 2; i++) {
      if (s.size() % i) continue;
      const string pref = s.substr(0, i);
      for (int j = 0; j < s.size() / i; j++) made += pref;
      if (made == s) return true;
      made.clear();
    }
    return false;
  }
};
