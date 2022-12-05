class Solution {
public:
  string reverseWords(string s) {
    int last = -1;
    for (int k = 0; k <= s.size(); k++) {
      if (k == s.size() || s[k] == ' ') {
        int i = last + 1;
        int j = k - 1;
        while (i < j) swap(s[i++], s[j--]);
        last = k;
      }
    }
    return s;
  }
};
