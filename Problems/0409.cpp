class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> um;
    for (char c : s) um[c]++;

    int res = 0;
    bool odd = false;
    for (auto [c, v] : um) {
      if (v % 2 && !odd) odd = true;
      res += v / 2;
    }
    return res * 2 + odd;
  }
};
