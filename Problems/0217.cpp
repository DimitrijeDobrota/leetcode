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

// Fun oneliner
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
  }
};
