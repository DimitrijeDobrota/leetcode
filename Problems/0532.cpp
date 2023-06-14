class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    int res = 0;
    if (k == 0) {
      unordered_map<int, int> um;
      for (int n : nums) um[n]++;
      for (const auto &[n, v] : um) res += v >= 2;
      return res;
    } else {
      unordered_set<int> us(nums.begin(), nums.end());
      for (const auto &n : us) res += us.count(n + k) + us.count(n - k);
      return res / 2;
    }
  }
};
