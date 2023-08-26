class Solution {
  public:
    int profitableSchemes(int n, int minProfit, const vector<int> &group, const vector<int> &profit) {
        int dp[101][101] = {{1}};
        int res = 0, mod = 1e9 + 7;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--) {
                for (int j = n - g; j >= 0; j--) {
                    int &cache = dp[min(i + p, minProfit)][j + g];
                    cache = (cache + dp[i][j]) % mod;
                }
            }
        }
        for (int x : dp[minProfit])
            res = (res + x) % mod;
        return res;
    }
};
