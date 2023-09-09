class Solution {
  public:
    string reverseParentheses(string s) const {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                reverse(begin(s) + st.top(), begin(s) + i);
                st.pop();
            }
        }

        int size = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '(' && s[i] != ')') s[size++] = s[i];
        s.resize(size);

        return s;
    }
};
