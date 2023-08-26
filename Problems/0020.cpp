class Solution {
    char is_open(char c) { return c == '(' || c == '[' || c == '{'; }
    char get_open_pair(char c) {
        switch (c) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return 0;
        }
    }

  public:
    bool isValid(string s) {
        stack<char> st;

        char t;
        for (auto c : s)
            if (is_open(c))
                st.push(c);
            else if ((t = get_open_pair(c)))
                if (!st.empty() && st.top() == t)
                    st.pop();
                else
                    return false;
            else
                return false;

        return st.empty();
    }
};
