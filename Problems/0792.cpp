class Solution {
  public:
    int numMatchingSubseq(const string &s, const vector<string> &words) const {
        static int pos[50001][26];
        const int n = size(s);
        int res = 0;

        memset(pos[n], 0x00, sizeof(pos[n]));
        for (int i = n - 1; i >= 0; i--) {
            memcpy(pos[i], pos[i + 1], sizeof(pos[i]));
            pos[i][s[i] - 'a'] = i + 1;
        }

        for (const auto &word : words) {
            int crnt = 0;
            for (const char c : word) {
                if (!pos[crnt][c - 'a']) goto next;
                crnt = pos[crnt][c - 'a'];
            }
            res++;
        next:;
        }

        return res;
    }
};
