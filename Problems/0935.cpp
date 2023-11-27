class Solution {
    static const int MOD = 1e9 + 7;

  public:
    int knightDialer(int n) const {
        static const vector<int> offsets[] = {{4, 6}, {8, 6},    {7, 9}, {4, 8}, {3, 9, 0},
                                              {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        vector<int> pdp(10, 1), dp(10);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                int res = 0;
                for (const int prev : offsets[j])
                    res = (res + pdp[prev]) % MOD;
                dp[j] = res;
            }
            swap(dp, pdp);
        }
        return accumulate(begin(pdp), end(pdp), 0, [&](int a, int acc) { return (acc + a) % MOD; });
    }
};
