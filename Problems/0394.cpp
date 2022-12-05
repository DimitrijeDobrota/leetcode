class Solution {
public:
  string decodeString(string s) {
    stack<int> is;
    stack<string> ss;

    ss.push("");
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        int res = 0;
        do {
          res *= 10;
          res += s[i] - '0';
        } while (isdigit(s[++i]));
        is.push(res);
        ss.push("");
      } else if (s[i] == ']') {
        string res = "";
        while (is.top()--) res += ss.top();
        is.pop();
        ss.pop();
        ss.top() += res;
      } else {
        ss.top() += s[i];
      }
    }

    return ss.top();
  }
};
