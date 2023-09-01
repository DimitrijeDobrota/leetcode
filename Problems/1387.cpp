class Solution {
    static inline constexpr const array<int, 1001> dp = []() constexpr -> array<int, 1001> {
        array<int, 1001> dp;
        dp[0] = 0;
        for (int i = 1; i <= 1000; i++) {
            int res = 0, n = i;
            while (n != 1) {
                n = (n % 2) ? 3 * n + 1 : n / 2;
                res++;
            }
            dp[i] = res;
        }
        return dp;
    }();

  public:
    int getKth(int lo, int hi, int k) {
        vector<int> vec(hi - lo + 1);

        iota(begin(vec), end(vec), lo);
        nth_element(begin(vec), begin(vec) + k - 1, end(vec),
                    [](const int a, const int b) { return dp[a] == dp[b] ? a < b : dp[a] < dp[b]; });

        return vec[k - 1];
    }
};
