class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size(), delta = INT_MAX / 2, res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < delta) {
                    delta = abs(target - sum);
                    res = sum;
                }
                (sum > target) ? k-- : j++;
            }
        }
        return res;
    }
};
