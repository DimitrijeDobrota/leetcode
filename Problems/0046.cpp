class Solution {
  vector<vector<int>> res;
  vector<int> crnt;
  vector<bool> seen;

  void rec(vector<int> &nums, int n) {
    if (n == nums.size()) {
      res.push_back(crnt);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (seen[i]) continue;
      seen[i] = true, crnt.push_back(nums[i]);
      rec(nums, n + 1);
      seen[i] = false, crnt.pop_back();
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    seen.resize(nums.size());
    rec(nums, 0);
    return res;
  }
};
