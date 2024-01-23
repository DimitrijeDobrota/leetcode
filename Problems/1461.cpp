class Solution {
  public:
    bool hasAllCodes(const string &s, const int k) const {
        static int seen[1 << 20];

        if (size(s) < (1 << k) + k - 1) return false;

        int crnt = 0;
        for (int i = 0; i < k; i++) {
            crnt = (crnt << 1) | (s[i] & 1);
        }

        const int mask = (1 << k) - 1;
        int res = 0;

        memset(seen, 0x00, sizeof(seen));
        for (int i = k; i < size(s); i++) {
            if (!seen[crnt]) seen[crnt] = true, res++;
            crnt = ((crnt << 1) | (s[i] & 1)) & mask;
        }
        if (!seen[crnt]) seen[crnt] = true, res++;
        return res == (1 << k);
    }
};
