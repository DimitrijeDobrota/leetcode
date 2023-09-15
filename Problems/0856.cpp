
// Stack solution
class Solution {
  public:
    int scoreOfParentheses(const string &s) {
        stack<int> st;
        int score = 0;
        for (const char c : s) {
            if (c == '(')
                st.push(score), score = 0;
            else {
                score = score ? 2 * score : 1;
                score += st.top();
                st.pop();
            }
        }
        return score;
    }
};

// O(1) memory solution
class Solution {
  public:
    int scoreOfParentheses(const string &s) {
        int res = 0, l = 0;
        for (int i = 0; i < s.size(); i++) {
            l += s[i] == '(' ? 1 : -1;
            if (s[i] == ')' && s[i - 1] == '(') res += 1 << l;
        }
        return res;
    }
};
