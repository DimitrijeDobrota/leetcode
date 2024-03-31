class Solution {
  public:
    int minimumSum(vector<int> &nums) const {
        static int dp[100001];
        const int n = size(nums);

        dp[0] = nums[0];
        for (int i = 1, mini = nums[0]; i < n; i++) {
            dp[i] = mini = min(mini, nums[i]);
        }

        int res = INT_MAX;
        for (int i = n - 2, mini = nums[n - 1]; i > 0; i--) {
            if (nums[i] > dp[i - 1] && nums[i] > mini) {
                res = min(res, nums[i] + dp[i - 1] + mini);
            }
            mini = min(mini, nums[i]);
        }

        return res != INT_MAX ? res : -1;
    }
};
