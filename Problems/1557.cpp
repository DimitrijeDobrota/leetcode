class Solution {
  public:
    bool closeStrings(const string &word1, const string &word2) {
        if (word1.size() != word2.size()) return false;
        const int n = word1.size();
        int w1[27] = {0}, w2[27] = {0};

        for (int i = 0; i < word1.size(); i++) {
            w1[word1[i] & 0x1F]++;
            w2[word2[i] & 0x1F]++;
        }

        for (int i = 1; i <= 26; i++)
            if ((bool)w1[i] ^ (bool)w2[i]) return false;

        sort(begin(w1), end(w1));
        sort(begin(w2), end(w2));

        for (int i = 0; i < 26; i++)
            if (w1[i] != w2[i]) return false;

        return true;
    }
};
