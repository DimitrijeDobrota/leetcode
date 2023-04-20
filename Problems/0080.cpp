class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int k = 1;
    for (int i = 1; i < nums.size(); i++) {
      nums[k++] = nums[i];
      if (nums[i] == nums[i - 1]) {
        while (++i < nums.size() && nums[i] == nums[k - 2])
          ;
        i--;
      }
    }
    return k;
  }
};
