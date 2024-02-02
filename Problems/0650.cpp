
// DP
class Solution {
    static int dp[1001][1001];

    int minSteps(const int n, int total, int clip) const {
        if (total == n) return 0;
        if (total > n) return 1000000;
        if (total + clip > n) return 1000000;
        if (dp[total][clip] != -1) return dp[total][clip];
        return dp[total][clip] = min(1 + minSteps(n, total + clip, clip), 2 + minSteps(n, total * 2, total));
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int minSteps(const int n) const { return n == 1 ? 0 : 1 + minSteps(n, 1, 1); }
};

int Solution::dp[1001][1001];

// Math
class Solution {
  public:
    int minSteps(int n) const {
        int res = 0, crnt = 2;
        while (n > 1) {
            while (n % crnt == 0) {
                res += crnt;
                n /= crnt;
            }
            crnt++;
        }
        return res;
    }
};
