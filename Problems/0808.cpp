class Solution {
  double dp[200][200] = {0};

  double calc(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1;
    if (b <= 0) return 0;
    if (dp[a][b] > 0) return dp[a][b];
    return dp[a][b] = 0.25 * (calc(a - 4, b) + calc(a - 3, b - 1) +
                              calc(a - 2, b - 2) + calc(a - 1, b - 3));
  }

public:
  double soupServings(int n) {
    return n > 4800 ? 1.0 : calc(ceil(n / 25.0), ceil(n / 25.0));
  }
};
