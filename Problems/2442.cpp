class Solution {
public:
  int countDistinctIntegers(const vector<int> &nums) {
    unordered_set<int> us(nums.begin(), nums.end());
    for (int n : nums) {
      int rev = 0;
      while (n % 10 == 0) n /= 10;
      do rev = (rev * 10) + n % 10;
      while ((n /= 10) > 0);
      us.insert(rev);
    }
    return us.size();
  }
};
