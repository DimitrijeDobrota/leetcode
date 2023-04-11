// Stack solution
class Solution {
public:
  string removeStars(string s) {
    stack<char> st;
    for (char c : s)
      if (c == '*')
        st.pop();
      else
        st.push(c);

    string res = "";
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

// Deque solution, avoid reversal
class Solution {
public:
  string removeStars(string s) {
    deque<char> dq;
    for (const char &c : s)
      if (c == '*')
        dq.pop_back();
      else
        dq.push_back(c);

    string res = "";
    while (!dq.empty()) {
      res += dq.front();
      dq.pop_front();
    }
    return res;
  }
};

// Two pointer, constant space, solution
class Solution {
public:
  string removeStars(string s) {
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '*')
        i--;
      else
        s[i++] = s[j];
    }
    return s.substr(0, i);
  }
};
