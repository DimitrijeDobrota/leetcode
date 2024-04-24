class Solution {
  public:
    int maxFreq(const string &s, int maxLetters, int sz, int _) const {
        unordered_map<string, int> um;
        static int count[26];
        int res = 0, uniq = 0;

        memset(count, 0x00, sizeof(count));
        for (int i = 0; i < sz; i++)
            if (!count[s[i] - 'a']++) uniq++;
        for (int i = sz; i < size(s); i++) {
            if (uniq <= maxLetters) um[s.substr(i - sz, sz)]++;
            if (!--count[s[i - sz] - 'a']) uniq--;
            if (!count[s[i] - 'a']++) uniq++;
        }

        if (uniq <= maxLetters) um[s.substr(size(s) - sz, sz)]++;
        for (const auto [_, c] : um)
            res = max(res, c);
        return res;
    }
};
