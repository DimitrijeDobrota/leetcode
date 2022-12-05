class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    for (char c : num) {
      while (k && !st.empty() && c < st.top()) {
        k--;
        st.pop();
      }
      if (st.empty() && c == '0') continue;
      st.push(c);
    }
    string res = "";

    while (!st.empty() && k--) st.pop();

    while (!st.empty()) {
      res = st.top() + res;
      st.pop();
    }

    if (res == "") return "0";

    return res;
  }
};
