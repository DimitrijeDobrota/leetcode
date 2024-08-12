class Solution {
  public:
    vector<int> buildArray(const vector<int> &nums) const {
        const int n = size(nums);
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
            res[i] = nums[nums[i]];
        return res;
    }
};
