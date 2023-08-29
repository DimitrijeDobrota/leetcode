class Solution {
    int dp[1001] = {0};

  public:
    int twoEggDrop(int n) {
        if (dp[n]) return dp[n];
        int res = n;
        for (int i = 1; i <= n; i++)
            res = min(res, 1 + max(i - 1, twoEggDrop(n - i)));
        return dp[n] = res;
    }
};
