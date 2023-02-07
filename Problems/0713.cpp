class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int res = 0, count = 0, prod = 1, start = 0;
    ;
    for (int i = 0; i < nums.size(); i++) {
      prod *= nums[i];
      while (prod >= k && start <= i) {
        prod /= nums[start++];
        count--;
      }
      res += i - start + 1;
    }
    return res;
  }
};
