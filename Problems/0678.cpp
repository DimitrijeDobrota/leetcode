class Solution {
  public:
    bool checkValidString(const string &s) const {
        int mini = 0, maxi = 0;
        for (const char c : s) {
            if (c == '(')
                mini++, maxi++;
            else if (c == ')')
                mini--, maxi--;
            else if (c == '*')
                maxi++, mini--;
            if (maxi < 0) return false;
            mini = max(mini, 0);
        }
        return mini == 0;
    }
};
