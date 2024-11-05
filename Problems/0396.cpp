class Solution {
  public:
    int maxRotateFunction(const vector<int> &nums) const {
        const int n = size(nums);
        int sum = 0, crnt = 0;

        for (int i = 0; i < n; i++) {
            crnt += i * nums[i];
            sum += nums[i];
        }

        int res = crnt;
        for (int i = n - 1; i >= 0; i--) {
            crnt += sum - nums[i] * n;
            res = max(res, crnt);
        }

        return res;
    }
};
