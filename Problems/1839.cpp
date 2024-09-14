class Solution {
  public:
    int longestBeautifulSubstring(const string &word) const {
        static const char *order = "aeiou";
        int i = 0, j = 0, cnt = 0;
        int res = 0;

        while (i < size(word)) {
            if (word[i] == order[j]) {
                while (word[i] == order[j])
                    i++, cnt++;
                if (++j == 5) res = max(res, cnt);
            } else {
                while (i < size(word) && word[i] != 'a')
                    i++;
                cnt = 0;
                j = 0;
            }
        }

        return res;
    }
};
