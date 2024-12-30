class Solution {
  public:
    vector<int> leftRightDifference(const vector<int> &nums) const {
        const int sum = accumulate(begin(nums), end(nums), 0);
        const int n = size(nums);
        vector<int> res(n);
        int acc = 0;

        for (int i = 0; i < n; i++) {
            res[i] = abs(sum - acc - nums[i] - acc);
            acc += nums[i];
        }

        return res;
    }
};
