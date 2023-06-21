class Solution {
public:
  long long minCost(const vector<int> &nums, const vector<int> &cost) {
    const auto calc = [&const](int target) {
      long long res = 0;
      for (int i = 0; i < nums.size(); i++)
        res += (long long)abs(nums[i] - target) * cost[i];
      return res;
    };

    long left = 1L, right = 1000000L;
    for (long num : nums) {
      left = min(left, num);
      right = max(right, num);
    }

    long ans = calc(1);
    while (left < right) {
      long mid = (left + right) / 2;
      long y1 = calc(mid), y2 = calc(mid + 1);
      ans = min(y1, y2);
      if (y1 < y2)
        right = mid;
      else
        left = mid + 1;
    }
    return ans;
  }
};
