class Solution {
    typedef array<array<int, 16>, 16> cache_t;
    static inline constexpr const cache_t cache = []() constexpr -> cache_t {
        cache_t cache = {{0}};
        for (int i = 1; i <= 15; i++) {
            cache[i].fill(INT_MAX);
            int count = 0;
            for (int j = 1; j <= 15; j++) {
                if (i % j == 0 || j % i == 0) cache[i][count++] = j;
            }
        }
        return cache;
    }();

    int dp[16][65536];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }

    int countArrangement(int n, int crnt = 1, uint16_t mask = 0) {
        if (crnt > n) return 1;
        if (dp[crnt][mask] != -1) return dp[crnt][mask];

        int res = 0;
        for (int num : cache[crnt]) {
            if (num > n) break;
            if (mask & (1 << num)) continue;
            res += countArrangement(n, crnt + 1, mask | (1 << num));
        }

        return dp[crnt][mask] = res;
    }
};
