class Solution {
    long long bin_exp_mod(long long a, long long b, long long mod) {
        a %= mod;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

  public:
    int countGoodNumbers(long long n) {
        static constexpr long long mod = 1e9 + 7;
        return bin_exp_mod(4, (n / 2), mod) * bin_exp_mod(5, (n + 1) / 2, mod) % mod;
    }
};
