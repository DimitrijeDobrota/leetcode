class Solution {
  public:
    int equalSubstring(const string &s, const string &t, const int maxCost) const {
        const int n = size(s);
        int res = 0, total = 0;

        for (int i = 0, j = 0; i < n; i++) {
            total += abs(s[i] - t[i]);
            while (maxCost < total) {
                total -= abs(s[j] - t[j]);
                j++;
            }
            res = max(res, i - j + 1);
        }

        return res;
    }
};
