class Solution {
  public:
    int minimumLength(const string &s) const {
        int count[26] = {0};
        int res = 0;

        for (const char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            res += (count[i] - 1) / 2;
        }

        return size(s) - 2 * res;
    }
};
