
// Recursive
class Solution {
    static double dp[101][101];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    double largestSumOfAverages(const vector<int> &nums, int k, int c = 0) {
        if (k == 0) return c == size(nums) ? 0 : -100000;
        if (dp[k][c] == dp[k][c]) return dp[k][c];

        double res = 0, sum = 0;
        for (int i = c, j = 1; i < size(nums); i++, j++) {
            sum += nums[i];
            res = max(res, sum / j + largestSumOfAverages(nums, k - 1, i + 1));
        }

        return dp[k][c] = res;
    }
};

double Solution::dp[101][101];

// Bottom-up DP
class Solution {
    static double dp[101][101];

  public:
    double largestSumOfAverages(const vector<int> &nums, int k, int c = 0) {
        static double sum[101], dp[101];
        const int n = size(nums);

        for (int i = 0, acc = 0; i < n; i++)
            sum[i + 1] = acc += nums[i];
        for (int i = 0; i < n; i++)
            dp[i] = (sum[n] - sum[i]) / (n - i);

        while (--k) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    dp[i] = max(dp[i], dp[j] + (sum[j] - sum[i]) / (j - i));
                }
            }
        }

        return dp[0];
    }
};
