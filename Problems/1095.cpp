#include <cmath>
class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int res = 0;
    for (int i : nums)
      if (int(log10(i) + 1) % 2 == 0) res++;
    return res;
  }
};
