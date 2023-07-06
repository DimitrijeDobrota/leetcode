class Solution {
public:
  int minSubArrayLen(int target, const vector<int> &nums) {
    int i = 0, j = 0, sum = 0, res = nums.size() + 1;
    while (true) {
      if (sum >= target) {
        res = min(res, j - i);
        sum -= nums[i++];
      } else {
        if (j == nums.size()) break;
        sum += nums[j++];
      }
    }
    if (res == nums.size() + 1) return 0;
    return res;
  }
};
