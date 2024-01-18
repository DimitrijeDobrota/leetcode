class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int concatenatedBinary(int n) const {
        long crnt = 0;
        for (int i = 1, size = 0; i <= n; i++) {
            if (__builtin_popcount(i) == 1) size++;
            crnt = ((crnt << size) + i) % MOD;
        }
        return crnt;
    }
};
