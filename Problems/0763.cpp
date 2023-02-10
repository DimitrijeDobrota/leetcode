class Solution {
public:
  vector<int> partitionLabels(string s) {
    unordered_set<char> seen;
    array<int, 26> count = {0};
    vector<int> res;

    for (char c : s) count[c - 'a']++;

    int len = 0, needed = 0;
    for (int i = 0; i < s.size(); i++) {
      len++;
      if (seen.count(s[i]))
        needed--;
      else {
        needed += count[s[i] - 'a'] - 1;
        seen.insert(s[i]);
      }

      if (!needed) {
        res.push_back(len);
        seen.clear();
        len = 0;
      }
    }

    return res;
  }
};
