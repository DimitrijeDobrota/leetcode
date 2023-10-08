class Solution {
    static int dp[501], pdp[501];

  public:
    int maxDotProduct(const vector<int> &nums1, const vector<int> &nums2) {
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;

        for (const int n : nums1) {
            maxi1 = max(maxi1, n);
            mini1 = min(mini1, n);
        }

        for (const int n : nums2) {
            maxi2 = max(maxi2, n);
            mini2 = min(mini2, n);
        }

        if (maxi1 < 0 && mini2 > 0) return maxi1 * mini2;
        if (mini1 > 0 && maxi2 < 0) return mini1 * maxi2;

        memset(dp, 0x00, sizeof(dp));
        memset(pdp, 0x00, sizeof(pdp));
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                dp[j] = max({pdp[j], dp[j + 1], nums1[i] * nums2[j] + pdp[j + 1]});
            }
            memcpy(pdp, dp, sizeof(dp));
        }

        return dp[0];
    }
};

int Solution::dp[501], Solution::pdp[501];
