class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> res;
    int acc = 0;
    for (auto i : nums) res.push_back(acc += i);
    return res;
  }
};
