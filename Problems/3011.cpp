class Solution {
  public:
    bool canSortArray(vector<int> &nums) {
        const int n = size(nums);

        int i = 0, prev = 0, cnt = std::popcount((unsigned)nums[0]);
        int mini = nums[0], maxi = nums[0];
        for (int j = 1; j < n; j++) {
            const int crnt = std::popcount((unsigned)nums[j]);
            if (cnt == crnt) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                continue;
            }
            if (mini < prev) return false;
            prev = maxi;
            mini = maxi = nums[j];
            cnt = crnt;
            i = j;
        }

        return mini >= prev;
    }
};
