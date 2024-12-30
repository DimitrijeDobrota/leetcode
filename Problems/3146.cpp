class Solution {
  public:
    int findPermutationDifference(const string &s, const string &t) const {
        static int pos[26];
        int res = 0;

        for (int i = 0; i < size(s); i++) {
            pos[s[i] - 'a'] = i;
        }

        for (int i = 0; i < size(t); i++) {
            res += abs(pos[t[i] - 'a'] - i);
        }

        return res;
    }
};
