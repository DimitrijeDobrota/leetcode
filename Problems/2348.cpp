class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long res = 0, count = 0;
    for (int crnt : nums) {
      if (!crnt)
        res += ++count;
      else
        count = 0;
    }
    return res;
  }
};
