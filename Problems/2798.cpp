class Solution {
  public:
    int numberOfEmployeesWhoMetTarget(const vector<int> &hours, int target) const {
        return count_if(begin(hours), end(hours), [&](int n) { return n >= target; });
    }
};
