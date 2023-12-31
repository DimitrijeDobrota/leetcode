class Solution {
  public:
    int maxLengthBetweenEqualCharacters(const string &s) const {
        static int index[27];
        int res = -1;
        memset(index, 0xFF, sizeof(index));
        for (int i = 0; i < s.size(); i++) {
            const int idx = s[i] & 0x1F;
            if (index[idx] == -1)
                index[idx] = i;
            else
                res = max(res, i - index[idx] - 1);
        }
        return res;
    }
};
