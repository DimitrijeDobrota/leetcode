class Solution {
public:
  int lengthOfLastWord(string s) {
    int i = s.size(), res = 0;
    while (--i >= 0 && isspace(s[i]))
      ;
    while (i >= 0 && !isspace(s[i--])) res++;
    return res;
  }
};
