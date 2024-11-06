class Solution {
  public:
    int findSubstringInWraproundString(const string &s) const {
        const int n = size(s);
        static int seen[26];

        memset(seen, 0x00, sizeof(seen));
        for (const char c : s)
            seen[c - 'a'] = 1;
        for (int i = 1, cnt = 1; i < n; i++) {
            cnt = (s[i] - s[i - 1] + 26) % 26 == 1 ? cnt + 1 : 1;
            seen[s[i] - 'a'] = max(seen[s[i] - 'a'], cnt);
        }

        return accumulate(seen, seen + 26, 0);
    }
};
