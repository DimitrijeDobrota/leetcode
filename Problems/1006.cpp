class Solution {
    static int other(int n) {
        if (n <= 0) return 0;
        int res = n;
        if (n > 1) res *= n - 1;
        if (n > 2) res /= n - 2;
        if (n > 3) res -= n - 3;
        return res + other(n - 4);
    }

  public:
    int clumsy(int n) const {
        int res = n;
        if (n > 1) res *= n - 1;
        if (n > 2) res /= n - 2;
        if (n > 3) res += n - 3;
        return res - other(n - 4);
    }
};
