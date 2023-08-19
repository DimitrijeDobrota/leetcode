class Solution {
  static constexpr bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  };

public:
  string &sortVowels(string &s) {
    vector<char> vowels;
    for (char c : s) {
      if (isvowel(tolower(c))) vowels.push_back(c);
    }

    sort(vowels.begin(), vowels.end());

    for (int i = 0, j = 0; i < s.size(); i++) {
      if (isvowel(tolower(s[i]))) s[i] = vowels[j++];
    }

    return s;
  }
};
