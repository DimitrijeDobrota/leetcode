class Solution {
  public:
    int minChanges(const string &s) const {
        int res = 0;
        for (int i = 1; i < s.size(); i += 2) {
            res += s[i] != s[i - 1];
        }
        return res;
    }
};
