class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> tmp;
    tmp.reserve(nums.size());
    int count = 0, idx = 0;
    for (int num : nums) {
      if (num == pivot)
        count++;
      else if (num > pivot)
        tmp.push_back(num);
      else
        nums[idx++] = num;
    }

    for (int i = 0; i < count; i++) nums[idx++] = pivot;
    for (int num : tmp) nums[idx++] = num;
    return nums;
  }
};
