class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int countHomogenous(const string &s) const {
        int res = 1, count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1])
                count = 1;
            else
                count++;
            res = (res + count) % MOD;
        }
        return res;
    }
};
