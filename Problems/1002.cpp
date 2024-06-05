class Solution {
  public:
    vector<string> commonChars(const vector<string> &words) const {
        static unsigned count[26];
        vector<string> res;

        memset(count, 0xFF, sizeof(count));
        for (const auto &word : words) {
            unsigned lcount[26] = {0};
            for (const char c : word)
                lcount[c - 'a']++;
            for (int i = 0; i < 26; i++)
                count[i] = min(count[i], lcount[i]);
        }

        for (int i = 0; i < 26; i++) {
            const string c(1, 'a' + i);
            for (int j = 0; j < count[i]; j++)
                res.push_back(c);
        }

        return res;
    }
};
