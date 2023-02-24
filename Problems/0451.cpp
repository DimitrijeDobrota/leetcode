class Solution {
public:
  string frequencySort(string s) {
    array<int, 128> um = {0};
    for (char c : s) um[c]++;
    sort(s.begin(), s.end(), [&um](char a, char b) {
      return um[a] > um[b] || (um[a] == um[b] && a < b);
    });
    return s;
  }
};
