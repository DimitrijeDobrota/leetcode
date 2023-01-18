class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int total, maxSum, curMax, minSum, curMin;

    total = curMax = curMin = 0;
    maxSum = minSum = nums[0];
    for (int &n : nums) {
      curMax = max(curMax + n, n);
      maxSum = max(maxSum, curMax);
      curMin = min(curMin + n, n);
      minSum = min(minSum, curMin);
      total += n;
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
  }
};
