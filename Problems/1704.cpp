class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  bool halvesAreAlike(string s) {
    int i = 0, j = s.size() / 2, count = 0;
    while (j < s.size())
      count += is_vowel(tolower(s[i++])) - is_vowel(tolower(s[j++]));
    ;
    return !count;
  }
};
