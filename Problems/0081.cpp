class Solution {
public:
  bool search(const vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return true;
      if (nums[mid] == nums[left]) {
        left++;
        continue;
      }

      bool pivotArr = nums[left] <= nums[mid];
      bool targetArr = nums[left] <= target;
      if ((pivotArr ^ targetArr) ? (pivotArr) : (nums[mid] < target)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};
