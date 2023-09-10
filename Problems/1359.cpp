class Solution {
  public:
    int countOrders(const int n) {
        long res = 1, mod = (long)1E9 + 7;
        for (int i = 1; i <= n; i++)
            res = res * (i * 2 - 1) * i % mod;
        return res;
    }
};
