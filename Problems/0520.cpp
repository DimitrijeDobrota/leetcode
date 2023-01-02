class Solution {
public:
  bool detectCapitalUse(string word) {
    int count = 0;
    for (char &c : word) count += c == toupper(c);
    return count == 0 || count == word.size() ||
           (count == 1 && word[0] == toupper(word[0]));
  }
};
