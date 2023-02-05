class Solution {
public:
  void sortColors(vector<int> &nums) {
    array<int, 3> arr;
    for (int n : nums) arr[n]++;
    int count = 0;
    for (int i = 0; i < 3; i++)
      while (arr[i]--) nums[count++] = i;
  }
};
