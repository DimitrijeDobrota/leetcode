class Solution {
  public:
    int minDeletions(const string &s) {
        int count[27] = {0};
        for (const char c : s)
            count[c & 0x1F]++;
        sort(rbegin(count), rend(count));

        int res = 0;
        for (int i = 1; i <= 26 && count[i]; i++) {
            const int diff = count[i] - count[i - 1] + 1;
            if (diff >= 0) {
                res += min(count[i], diff);
                count[i] -= min(count[i], diff);
            }
        }
        return res;
    }
};
