class Solution {
  public:
    int countWays(vector<int> &nums) const {
        sort(begin(nums), end(nums));

        const int n = size(nums);
        int res = 0, sel = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i + 1 <= nums[i]) continue;
            if (i + 1 < nums[i + 1]) res++;
        }

        if (n > nums[n - 1]) res++;
        return res + (nums[0] != 0);
    }
};
