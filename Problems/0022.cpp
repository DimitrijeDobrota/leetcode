class Solution {
  vector<string> res;
  stack<char> st;
  string crnt = "";

  void dfs(int n) {
    static const char o = '(', c = ')';

    if (!n) {
      if (st.empty()) res.push_back(crnt);
      return;
    }

    st.push(o), crnt += o;
    dfs(n - 1);
    st.pop(), crnt.pop_back();

    if (st.empty()) return;

    crnt += c, st.pop();
    dfs(n - 1);
    crnt.pop_back();
    st.push(c);
  }

public:
  vector<string> generateParenthesis(int n) {
    dfs(n * 2);
    return res;
  }
};
