class Solution {
public:
  int singleNumber(const vector<int> &nums) {
    int mask1 = 0, mask2 = 0;
    for (int n : nums) {
      mask1 = (mask1 ^ n) & ~mask2;
      mask2 = (mask2 ^ n) & ~mask1;
    }
    return mask1;
  }
};
