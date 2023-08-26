class Solution {
  public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s)
            if (st.empty() || c != st.top())
                st.push(c);
            else
                st.pop();

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
