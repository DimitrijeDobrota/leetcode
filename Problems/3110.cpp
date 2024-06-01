class Solution {
  public:
    int scoreOfString(const string &s) const {
        int res = 0;
        for (int i = 1; i < size(s); i++)
            res += abs(s[i] - s[i - 1]);
        return res;
    }
};
