class Solution {
  public:
    int beautifulSubsets(const vector<int> &nums, const int g) const {
        const int n = size(nums);
        vector<map<int, int>> mat(g);
        int res = 1;

        for (const int n : nums)
            mat[n % g][n]++;
        for (const auto &mp : mat) {
            int p = 0, dp0 = 1, dp1 = 0;
            for (const auto [k, v] : mp) {
                const int t = (1 << v) - 1;
                dp0 += dp1;
                dp1 = t * (p + g == k ? dp0 - dp1 : dp0);
                p = k;
            }
            res *= dp0 + dp1;
        }

        return res - 1;
    }
};
