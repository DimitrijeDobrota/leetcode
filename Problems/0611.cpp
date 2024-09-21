class Solution {
  public:
    int triangleNumber(vector<int> &nums) const {
        const int n = size(nums);
        int res = 0;

        sort(begin(nums), end(nums));
        for (int k = 2; k < n; k++) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] <= nums[k])
                    i++;
                else
                    res += j - i, j--;
            }
        }

        return res;
    }
};
