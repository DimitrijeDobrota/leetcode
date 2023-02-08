class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size(), res = 0, sum = 0;
    unordered_map<int, int> um;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) sum = prefix[i] = sum + nums[i];

    for (int i = 0; i < n; i++) {
      if (prefix[i] == k) res++;
      if (um.count(prefix[i] - k)) res += um[prefix[i] - k];
      um[prefix[i]]++;
    }

    return res;
  }
};
