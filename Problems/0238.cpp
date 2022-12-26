class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> answer(n, 1);

    int acc1 = 1, acc2 = 1;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      answer[i] *= acc1;
      answer[j] *= acc2;
      acc1 *= nums[i];
      acc2 *= nums[j];
    }

    return answer;
  }
};
