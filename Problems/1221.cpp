class Solution {
  public:
    int balancedStringSplit(const string &s) const {
        const int n = size(s);
        int res = 0;

        for (int i = 0; i < n; i++) {
            int count = s[i] == 'L' ? 1 : -1;
            while (count != 0) {
                count += s[++i] == 'L' ? 1 : -1;
            }
            res++;
        }

        return res;
    }
};
