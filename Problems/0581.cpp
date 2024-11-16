class Solution {
  public:
    int findUnsortedSubarray(const vector<int> &nums) const {
        const int n = size(nums);
        int mini = nums[n - 1], maxi = nums[0];
        int low = -1, high = -2;

        for (int i = 1; i < n; i++) {
            mini = min(mini, nums[n - i - 1]);
            maxi = max(maxi, nums[i]);

            if (nums[i] < maxi) high = i;
            if (nums[n - i - 1] > mini) low = n - i - 1;
        }

        return high - low + 1;
    }
};
