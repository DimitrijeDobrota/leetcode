class Solution {
  public:
    int countSubstrings(const string &s, const string &t) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                for (int pos = 0, miss = 0; i + pos < s.size() && j + pos < t.size(); ++pos) {
                    if (s[i + pos] != t[j + pos] && ++miss > 1) break;
                    res += miss;
                }
            }
        }
        return res;
    }
};
