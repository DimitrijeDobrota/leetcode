class Solution {
    unordered_set<string> st;
    int maxi = 0;

    void rec(const string &s, int idx, const string &crnt, int open, int close) {
        if (idx == size(s)) {
            if (open != 0) return;

            if (size(crnt) > maxi) {
                maxi = size(crnt);
                st.clear();
            }

            if (size(crnt) == maxi && !st.count(crnt)) {
                st.insert(crnt);
            }

            return;
        }

        if (s[idx] == '(') {
            if (open + 1 <= close) rec(s, idx + 1, crnt + '(', open + 1, close);
            rec(s, idx + 1, crnt, open, close);
        } else if (s[idx] == ')') {
            if (open > 0) rec(s, idx + 1, crnt + ')', open - 1, close - 1);
            rec(s, idx + 1, crnt, open, close);
        } else
            rec(s, idx + 1, crnt + s[idx], open, close);
    }

  public:
    vector<string> removeInvalidParentheses(const string &s) {
        rec(s, 0, "", 0, count(begin(s), end(s), ')'));
        return vector(begin(st), end(st));
    }
};
