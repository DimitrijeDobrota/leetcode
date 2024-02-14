class Solution {
  public:
    long long minimumCost(const string &s) const {
        static long long dp[100001];

        const int n = size(s);
        if (n == 1) return 0;

        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = s[i] == s[i - 1] ? dp[i - 1] : dp[i - 1] + i;
        }

        long long res = LLONG_MAX, acc = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] != s[i + 1]) acc += n - i - 1;
            res = min(res, dp[i] + acc);
        }

        return res;
    }
};

// O(1) space
class Solution {
  public:
    long long minimumCost(const string &s) const {
        long long res = 0;

        for (int i = 1, n = size(s); i < n; i++) {
            if (s[i] != s[i - 1]) res += min(i, n - i);
        }

        return res;
    }
};
