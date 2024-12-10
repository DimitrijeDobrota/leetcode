class Solution {
  public:
    int maximumLength(const string &s) const {
        static int count[26][3];
        int cnt = 0, prev = s[0];

        memset(count, 0xFF, sizeof(count));
        for (const char c : s) {
            if (c == prev)
                cnt++;
            else {
                prev = c;
                cnt = 1;
            }

            const int idx = c - 'a';
            auto mini = min_element(count[idx], count[idx] + 3);
            if (cnt > *mini) *mini = cnt;
        }

        int res = -1;
        for (int i = 0; i < 26; i++) {
            res = max(res, *min_element(count[i], count[i] + 3));
        }

        return res;
    }
};
