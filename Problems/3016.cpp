class Solution {
  public:
    int minimumPushes(const string &word) const {
        int count[26] = {0};
        for (const char c : word)
            count[c - 'a']++;

        sort(count, count + 26, greater());

        int res = 0, key = 1, cnt = 0;
        for (int i = 0; i < 26; i++) {
            res += key * count[i];
            if (++cnt == 8) key++, cnt = 0;
        }
        return res;
    }
};
