class Solution {
  public:
    int addMinimum(const string &word) const {
        static const int add[3][3] = {{2, 1, 0}, {0, 2, 1}, {1, 0, 2}};
        int res = 0, prev = 2;

        for (const char c : word) {
            const int idx = c - 'a';
            res += add[idx][prev];
            prev = idx;
        }

        return res + 2 - prev;
    }
};
