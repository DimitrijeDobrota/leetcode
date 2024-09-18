class Solution {
  public:
    int findLength(const vector<int> &nums1, const vector<int> &nums2) const {
        static int dp[1002][1002];
        int res = 0;

        memset(dp, 0x00, sizeof(dp));
        for (int i = size(nums1) - 1; i >= 0; i--) {
            for (int j = size(nums2) - 1; j >= 0; j--) {
                if (nums1[i] != nums2[j]) continue;
                dp[i][j] = dp[i + 1][j + 1] + 1;
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};
