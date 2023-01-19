class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int n = nums.size(), sum = 0, res = 0;
    vector<int> dp(k, 0);

    dp[0] = 1;
    for (int num : nums) {
      sum += num;
      int rem = sum % k;
      if (rem < 0) rem += k;
      res += dp[rem]++;
    }
    return res;
  }
};
