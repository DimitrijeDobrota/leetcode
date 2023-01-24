// Intuitive solution
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

// Intuitive solution, better execution
// avoids recomputation of squares
// avoids reversal of the array
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size(), i = 0, j = nums.size() - 1;
    vector<int> res(n);
    for_each(nums.begin(), nums.end(), [](int &a) { a *= a; });
    while (i <= j) res[--n] = nums[i] > nums[j] ? nums[i++] : nums[j--];
    return res;
  }
};
