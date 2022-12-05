class Solution {
public:
  string reverseWords(string s) {
    string res = "";
    string buff = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        buff += s[i];
      } else if (buff != "") {
        res = buff + " " + res;
        buff = "";
      }
    }
    if (buff != "") res = buff + " " + res;
    if (res != "") res.pop_back();
    return res;
  }
};
