class Solution {
    static int count[27];
    static inline bool valid(const string &word) {
        static int cnt[27];
        memset(cnt, 0x00, sizeof(count));
        for (const char c : word) {
            const int idx = c & 0x1F;
            if (++cnt[idx] > count[idx]) return false;
        }
        return true;
    }

  public:
    int countCharacters(const vector<string> &words, const string &chars) const {
        memset(count, 0x00, sizeof(count));
        for (const char c : chars)
            count[c & 0x1F]++;

        int res = 0;
        for (const auto &word : words) {
            if (valid(word)) res += word.size();
        }
        return res;
    }
};

int Solution::count[27];
