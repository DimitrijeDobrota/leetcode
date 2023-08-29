class Solution {
  public:
    int minSteps(const string &s, const string &t) {
        int count[27] = {0}, res = 0;
        for (const char c : s)
            count[c & 0x1F]++;
        for (const char c : t)
            count[c & 0x1F]--;
        for (int i = 1; i <= 26; i++)
            res += abs(count[i]);
        return res;
    }
};
