class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (!nums.size()) return {};
    vector<string> res;
    int start = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1] + 1) continue;
      if (i - start > 1)
        res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
      else
        res.push_back(to_string(nums[start]));
      start = i;
    }
    if (nums.size() - start > 1)
      res.push_back(to_string(nums[start]) + "->" + to_string(nums.back()));
    else
      res.push_back(to_string(nums[start]));

    return res;
  }
};
