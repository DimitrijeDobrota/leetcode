class Solution {
    static int8_t dp[1 << 20];

    int rec(int maxi, int tgt, int k) {
        if (dp[k] != 0) return dp[k] > 0;
        if (tgt <= 0) return false;

        for (int i = 1, mask = 1; i <= maxi; mask <<= 1, i++) {
            if (k & mask) continue;
            if (rec(maxi, tgt - i, k | mask)) continue;
            dp[k] = 1;
            return true;
        }

        dp[k] = -1;
        return false;
    }

  public:
    bool canIWin(int maxi, int tgt) {
        if (tgt <= maxi) return true;

        const int sum = maxi * (maxi + 1) / 2;
        if (sum < tgt) return false;
        if (sum == tgt) return maxi % 2;

        memset(dp, 0x00, sizeof(dp));
        return rec(maxi, tgt, 0);
    }
};

int8_t Solution::dp[1 << 20];
