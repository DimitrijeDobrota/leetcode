class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size(), limit = 0;
    vector<int> num(n);
    num[0] = 0;
    for (int i = 0; i <= limit && i < n; i++) {
      for (int j = limit + 1; j <= i + nums[i] && j < n; j++)
        num[j] = num[i] + 1;
      limit = max(limit, i + nums[i]);
    }
    return num.back();
  }
};
