class Solution {
    static int dp[127][127];

    static int digits(int x) {
        if (x == 1) return 0;
        if (x < 10) return 1;
        if (x < 100) return 2;
        return 3;
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int getLengthOfOptimalCompression(const string &s, int k, int crnt = 0) const {
        const int n = s.size();
        if (k < 0) return n;
        if (crnt >= n || n - crnt <= k) return 0;
        if (dp[crnt][k] != -1) return dp[crnt][k];
        int res = n, cnt[27] = {0};
        for (int j = crnt, maxi = 0; j < n; j++) {
            maxi = max(maxi, ++cnt[s[j] & 0x1F]);
            res = min(res,
                      1 + digits(maxi) + getLengthOfOptimalCompression(s, k - (j - crnt + 1 - maxi), j + 1));
        }
        return dp[crnt][k] = res;
    }
};

int Solution::dp[127][127];
