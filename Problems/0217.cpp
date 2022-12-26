class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> us;
    for (int n : nums)
      if (us.count(n))
        return true;
      else
        us.insert(n);
    return false;
  }
};
