class Solution {
public:
  int distinctAverages(vector<int> &nums) {
    unordered_set<int> us;

    sort(nums.begin(), nums.end());
    for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
      us.insert(nums[i] + nums[j]);

    return us.size();
  }
};
