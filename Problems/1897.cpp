class Solution {
  public:
    bool makeEqual(const vector<string> &words) const {
        int count[27] = {0};
        for (const string &word : words) {
            for (const char c : word)
                count[c & 0x1F]++;
        }
        for (int i = 1; i <= 26; i++) {
            if (count[i] % words.size()) return false;
        }
        return true;
    }
};
