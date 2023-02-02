class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<char> um(26);
    for (int i = 0; i < order.size(); i++) um[order[i] - 'a'] = 'a' + i;
    for (string &word : words)
      for_each(word.begin(), word.end(), [&um](char &c) { c = um[c - 'a']; });
    return is_sorted(words.begin(), words.end());
  }
};
