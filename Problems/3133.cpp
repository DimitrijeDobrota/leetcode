class Solution {
  public:
    long long minEnd(int n, long long x) const {
        using ull = unsigned long long;

        for (ull i = 1, j = n - 1; j > 0 && i > 0;) {
            if (!(x & i)) x |= j & 1 ? i : 0, j >>= 1;
            i <<= 1;
        }

        return x;
    }
};
