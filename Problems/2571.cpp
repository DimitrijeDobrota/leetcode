class Solution {
    int rec(int n, int idx) const {
        if (n == 0) return 0;
        int res = INT_MAX, steps = 0;
        for (int i = idx, mask = 1 << idx; n != 0 && i < 17; i++, mask <<= 1) {
            if ((n & mask) == 0) continue;
            res = min(res, 1 + rec(n - mask, i + 1) + steps);
            n += mask, steps++;
        }
        return res;
    }

  public:
    int minOperations(int n) const { return rec(n, 0); }
};

// Greedy
class Solution {
  public:
    int minOperations(unsigned n) const {
        int res = 0;
        for (unsigned i = 0, mask = 1; i < 17; i++, mask <<= 1) {
            if (popcount(n + mask) < popcount(n)) res++, n += mask;
        }
        return res + popcount(n);
    }
};
