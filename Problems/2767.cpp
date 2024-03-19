class Solution {
    int rec(const char *s, const int n, int i) const {
        if (i == n) return 0;
        if (s[i] == '0') return -1;

        int res = INT_MAX, crnt = 0;
        for (; i < n; i++) {
            crnt = (crnt << 1) | (s[i] & 1);
            if (15625 % crnt == 0) {
                const int next = rec(s, n, i + 1);
                if (next == -1) continue;
                res = min(res, 1 + next);
            }
        }

        return res != INT_MAX ? res : -1;
    }

  public:
    int minimumBeautifulSubstrings(const string &s) const { return rec(s.data(), size(s), 0); }
};
