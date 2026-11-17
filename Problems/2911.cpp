class Solution {
  public:
    int minimumChanges(const std::string &s, int k) const {
        const auto n = std::size(s);
        const int inf = n + 1;

        std::vector<std::vector<int>> divisors(n + 1);
        for (int divisor = 1; divisor * 2 <= n; divisor++) {
            for (int length = divisor * 2; length <= n; length += divisor) {
                divisors[length].emplace_back(divisor);
            }
        }

        std::vector<std::vector<int>> cost(n, std::vector(n, inf));
        for (int length = 2; length <= n; length++) {
            for (int left = 0; left + length <= n; left++) {
                const int right = left + length - 1;

                for (const int d : divisors[length]) {
                    int changes = 0;

                    for (int offset = 0; offset < d; offset++) {
                        int lo = left + offset;
                        int hi = left + length - d + offset;

                        while (lo < hi) {
                            changes += s[lo] != s[hi];
                            lo += d;
                            hi -= d;
                        }
                    }

                    cost[left][right] = std::min(cost[left][right], changes);
                }
            }
        }

        std::vector<std::vector<int>> dp(k + 1, std::vector(n + 1, inf));

        dp[0][0] = 0;
        for (int parts = 1; parts <= k; parts++) {
            for (int end = 2 * parts; end <= n; end++) {
                for (int start = 2 * (parts - 1); start <= end - 2; start++) {
                    if (dp[parts - 1][start] == inf) continue;

                    dp[parts][end] = std::min(dp[parts][end], dp[parts - 1][start] + cost[start][end - 1]);
                }
            }
        }

        return dp[k][n];
    }
};
