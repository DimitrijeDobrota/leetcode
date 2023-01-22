// O(n) memory solution
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    vector<int> t(k);
    for (int i = 0; i < k; i++) t[i] = nums[nums.size() - k + i];
    for (int i = nums.size() - k - 1; i >= 0; i--) nums[i + k] = nums[i];
    for (int i = 0; i < k; i++) nums[i] = t[i];
  }
};

// O(1) memory solution
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
