class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> um(26, 0);
    for (char c : s) um[c - 'a']++;
    for (int i = 0; i < s.size(); i++)
      if (um[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
