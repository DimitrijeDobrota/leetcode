class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int maxi = 0;
    unordered_set<char> us;
    for (int i = 0, j = 0; j < size(s); j++) {
      while (us.count(s[j])) us.erase(s[i++]);
      maxi = max(j - i + 1, maxi);
      us.insert(s[j]);
    }
    return maxi;
  }
};
