class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    long maxi = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      mp[nums[i]]++;

      if (i < k - 1) continue;
      if (mp.size() == k) maxi = max(maxi, sum);
      int &tmp = nums[i - k + 1];
      sum -= tmp;
      if (--mp[tmp] == 0) mp.erase(tmp);
    }
    return maxi;
  }
};
