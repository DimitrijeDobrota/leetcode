class Solution {
public:
  int thirdMax(vector<int> &nums) {
    long long firstMax = numeric_limits<long long>::min();
    long long secondMax = numeric_limits<long long>::min();
    long long thirdMax = numeric_limits<long long>::min();

    for (int &num : nums) {
      if (firstMax == num || secondMax == num || thirdMax == num) { continue; }

      if (firstMax <= num) {
        thirdMax = secondMax;
        secondMax = firstMax;
        firstMax = num;
      } else if (secondMax <= num) {
        thirdMax = secondMax;
        secondMax = num;
      } else if (thirdMax <= num) {
        thirdMax = num;
      }
    }

    if (thirdMax == numeric_limits<long long>::min()) return firstMax;

    return thirdMax;
  }
};
