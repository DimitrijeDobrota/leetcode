class Solution {
  public:
    string findLongestWord(const string &s, const vector<string> &dictionary) const {
        static int count[1001][26];
        const int n = size(s);
        string res;

        memset(count[n], 0x00, sizeof(count[n]));
        for (int i = n - 1; i >= 0; i--) {
            memcpy(count[i], count[i + 1], sizeof(count[n]));
            count[i][s[i] - 'a'] = i + 1;
        }

        for (const auto &word : dictionary) {
            int pos = 0;
            for (const char c : word) {
                const int idx = c - 'a';
                if (!count[pos][idx]) goto next;
                pos = count[pos][idx];
            }

            if (size(word) > size(res))
                res = word;
            else if (size(word) == size(res))
                res = min(res, word);

        next:;
        }

        return res;
    }
};
