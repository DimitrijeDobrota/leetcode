class Solution {
  public:
    int takeCharacters(const string &s, int k) const {
        const int n = size(s);
        int count[3] = {0};

        for (const char c : s)
            count[c - 'a']++;
        if (count[0] < k || count[1] < k || count[2] < k) return -1;

        int res = n;
        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            count[s[i] - 'a']--;

            while (count[0] < k || count[1] < k || count[2] < k) {
                count[s[j--] - 'a']++;
            }

            res = min(res, i - j);
        }

        return res + n - 1;
    }
};
