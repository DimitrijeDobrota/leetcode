class Solution {
public:
  int minimumDeviation(vector<int> &nums) {
    int res = INT_MAX, mini = INT_MAX;
    for (auto &num : nums) {
      num = num % 2 ? num * 2 : num;
      mini = min(mini, num);
    }

    make_heap(begin(nums), end(nums));
    while (nums.front() % 2 == 0) {
      res = min(res, nums.front() - mini);
      mini = min(mini, nums.front() / 2);
      pop_heap(begin(nums), end(nums));
      nums.back() /= 2;
      push_heap(begin(nums), end(nums));
    }

    return min(res, nums.front() - mini);
  }
};
