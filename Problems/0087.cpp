class Solution {
  unordered_map<string, bool> um;

public:
  bool isScramble(string s1, string s2) {
    if (um.count(s1 + s2)) return um[s1 + s2];
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;

    vector<int> count(128, 0);
    int n = s1.size();
    um[s1 + s2] = false;

    for (int i = 0; i < n; i++) count[s1[i]]++, count[s2[i]]--;
    for (int n : count)
      if (n) return false;

    for (int k = 1; k < n; k++) {
      if (isScramble(s1.substr(0, k), s2.substr(0, k)) &&
              isScramble(s1.substr(k), s2.substr(k)) ||
          isScramble(s1.substr(0, k), s2.substr(n - k)) &&
              isScramble(s1.substr(k), s2.substr(0, n - k))) {
        um[s1 + s2] = true;
        return true;
      }
    }
    return false;
  }
};
