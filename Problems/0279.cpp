class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX - 1);
        vector<int> primes;

        for (int i = 1; i <= sqrt(n); i++)
            primes.push_back(i * i);

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < primes.size() && primes[j] <= i; j++)
                dp[i] = min(dp[i], dp[i - primes[j]] + 1);

        return dp[n];
    }
};
