class Solution {
  public:
    int minHeightShelves(const vector<vector<int>> &books, int shelfWidth) const {
        static int dp[1001];
        memset(dp, 0x7F, sizeof(dp));
        const int n = books.size();

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int left = shelfWidth, height = 0;
            for (int j = i; j > 0 && books[j - 1][0] <= left; j--) {
                left -= books[j - 1][0];
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n];
    }
};
