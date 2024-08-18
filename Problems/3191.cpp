class Solution {
  public:
    int minOperations(vector<int> &nums) const {
        const int n = size(nums);
        int res = 0;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i]) continue;
            nums[i + 1] = !nums[i + 1];
            nums[i + 2] = !nums[i + 2];
            res++;
        }

        if (!nums[n - 2] || !nums[n - 1]) return -1;
        return res;
    }
};
