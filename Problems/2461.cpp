class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    long long maxi = LLONG_MIN;
    unordered_set<int> us;
    int i = 0;
    long long sum = 0ll;
    for (int j = 0; j <= size(nums);) {
      while (us.find(nums[j]) != us.end()) {
        sum -= nums[i];
        us.erase(nums[i++]);
      }
      if (j - i < k) {
        sum += nums[j];
        us.insert(nums[j++]);
      }
      if (j > size(nums)) break;
      if (j - i == k) {
        maxi = max(sum, maxi);
        sum -= nums[i];
        us.erase(nums[i++]);
      }
    }
    return maxi == LLONG_MIN ? 0 : maxi;
  }
};
