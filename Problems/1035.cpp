class Solution {
    int dp[500][500];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }

    int maxUncrossedLines(const vector<int> &nums1, const vector<int> &nums2, int i = 0, int j = 0) {
        if (i >= nums1.size() || j >= nums2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res;
        if (nums1[i] == nums2[j])
            res = 1 + maxUncrossedLines(nums1, nums2, i + 1, j + 1);
        else {
            res = max(maxUncrossedLines(nums1, nums2, i + 1, j), maxUncrossedLines(nums1, nums2, i, j + 1));
        }

        return dp[i][j] = res;
    }
};
