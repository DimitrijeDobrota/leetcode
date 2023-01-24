class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> res;
    int acc = 0;
    for (auto i : nums) res.push_back(acc += i);
    return res;
  }
};

// using lambda function
class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    int acc = 0;
    for_each(nums.begin(), nums.end(), [&acc](int &a) { a = acc += a; });
    return nums;
  }
};
