class Solution {
  bool is_op(const string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
  }

public:
  int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0) return 0;

    stack<long long> st;
    for (string &s : tokens) {
      if (is_op(s)) {
        long long y = st.top();
        st.pop();
        long long x = st.top();
        st.pop();
        switch (s[0]) {
        case '+': st.push(x + y); break;
        case '-': st.push(x - y); break;
        case '*': st.push(x * y); break;
        case '/': st.push(x / y); break;
        }
      } else
        st.push(stoi(s));
    }
    return st.top();
  }
};
