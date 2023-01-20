class Solution {
  vector<vector<int>> res;
  vector<int> seq;

public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    dfs(nums, 0);
    return res;
  }

  void dfs(vector<int> &nums, int pos) {
    if (seq.size() > 1) res.push_back(seq);
    unordered_set<int> hash;
    for (int i = pos; i < nums.size(); i++) {
      if ((seq.empty() || nums[i] >= seq.back()) && !hash.count(nums[i])) {
        seq.push_back(nums[i]);
        dfs(nums, i + 1);
        seq.pop_back();
        hash.insert(nums[i]);
      }
    }
  }
};
