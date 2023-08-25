class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    sort(begin(nums), end(nums));

    int res = 1, j = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[j] > k) j = i, res++;
    }
    return res;
  }
};
