class Solution {
  public:
    int longestSubstring(const string &s, int k) const {
        const int n = size(s);
        static int count[26];
        int res = 0, maxUnique = 0;

        memset(count, 0x00, sizeof(count));
        for (const char c : s)
            maxUnique += !count[c - 'a']++;

        for (int l = 1; l <= maxUnique; l++) {
            memset(count, 0x00, sizeof(count));
            int i = 0, j = 0, unique = 0, least = 0;
            while (j < n) {
                if (unique <= l) {
                    unique += !count[s[j] - 'a']++;
                    least += count[s[j] - 'a'] == k;
                    j++;
                } else {
                    least -= count[s[i] - 'a'] == k;
                    unique -= !--count[s[i] - 'a'];
                    i++;
                }

                if (unique == l && least == l) {
                    res = max(res, j - i);
                }
            }
        }

        return res;
    }
};
