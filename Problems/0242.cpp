class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> um(26, 0);
    for (char c : s) um[c - 'a']++;
    for (char c : t)
      if (!um[c - 'a'])
        return false;
      else
        um[c - 'a']--;
    return true;
  }
};
