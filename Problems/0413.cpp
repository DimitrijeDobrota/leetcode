class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int total = 0, crnt, cdiff = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
      int diff = nums[i] - nums[i - 1];
      if (diff != cdiff) {
        crnt = 0;
        cdiff = diff;
        continue;
      }
      total += ++crnt;
    }
    return total;
  }
};
