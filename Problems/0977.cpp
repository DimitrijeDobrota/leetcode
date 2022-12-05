class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> res;
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
      int n1 = nums[i] * nums[i];
      int n2 = nums[j] * nums[j];
      if (n1 > n2) {
        res.push_back(n1);
        i++;
      } else {
        res.push_back(n2);
        j--;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
