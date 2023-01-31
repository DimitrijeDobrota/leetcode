class Solution {
  vector<string> res;

  void rec(string &s, int st, string crnt) {
    while (st < s.size() && !isalpha(s[st])) crnt += s[st++];
    if (st == s.size()) {
      res.push_back(crnt);
      return;
    }

    char c = tolower(s[st]);
    rec(s, st + 1, crnt + c);
    rec(s, st + 1, crnt + (char)toupper(c));
  }

public:
  vector<string> letterCasePermutation(string s) {
    rec(s, 0, "");
    return res;
  }
};
