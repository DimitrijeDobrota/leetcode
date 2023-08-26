class Solution {
  public:
    int partitionDisjoint(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n), right(n);

        left[0] = nums[0];
        right.back() = nums.back();
        for (int i = 1; i < nums.size(); i++) {
            left[i] = max(nums[i], left[i - 1]);
            right[n - i - 1] = min(nums[n - i - 1], right[n - i]);
        }

        for (int i = 0; i < n - 1; i++)
            if (left[i] <= right[i + 1]) return i + 1;
        return -1;
    }
};
