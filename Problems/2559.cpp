class Solution {
    static bool is_vowel(const char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

  public:
    vector<int> vowelStrings(const vector<string> &words, const vector<vector<int>> &queries) const {
        static int count[100002];
        const int n = size(words), m = size(queries);

        memset(count, 0x00, sizeof(count));
        for (int i = 0, acc = 0; i < n; i++) {
            if (is_vowel(words[i].front()) && is_vowel(words[i].back())) acc++;
            count[i + 1] = acc;
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = count[queries[i][1] + 1] - count[queries[i][0]];
        }
        return res;
    }
};
