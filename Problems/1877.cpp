class Solution {
public:
  int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int res = INT_MIN, i = 0, j = nums.size() - 1;
    while (i < j) res = max(res, nums[i++] + nums[j--]);
    return res;
  }
};
