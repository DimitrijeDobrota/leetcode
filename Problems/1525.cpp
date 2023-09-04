class Solution {
  public:
    int numSplits(const string &s) {
        bool seen[27] = {0};
        int uniq[100000] = {0};

        for (int i = 0, acc = 0; i < s.size(); i++) {
            if (!seen[s[i] & 0x1F]) {
                seen[s[i] & 0x1F] = true;
                acc++;
            }
            uniq[i] = acc;
        }

        memset(seen, 0x00, sizeof(seen));
        seen[s.back() & 0x1F] = true;

        int res = 0;
        for (int i = s.size() - 2, acc = 1; i >= 0; i--) {
            if (uniq[i] == acc) res++;
            if (seen[s[i] & 0x1F]) continue;
            seen[s[i] & 0x1F] = true;
            acc++;
        }

        return res;
    }
};
