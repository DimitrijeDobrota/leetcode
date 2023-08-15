// 1551. Minimum Operations to Make Array Equal
class Solution {
public:
  int minOperations(int n) {
    int k = n / 2;
    return n % 2 ? k * (k + 1) : k * k;
  }
};
