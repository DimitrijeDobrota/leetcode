class Solution {
  public:
    bool isValid(const string &s) const {
        static char st[20001];
        int n = 0;
        for (const char c : s) {
            if (c != 'c')
                st[n++] = c;
            else {
                if (n < 2) return false;
                if (st[n - 1] != 'b') return false;
                if (st[n - 2] != 'a') return false;
                n -= 2;
            }
        }
        return n == 0;
    }
};
