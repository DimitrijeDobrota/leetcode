class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int n = nums.size(), leftBound = -1, lastMin = -1, lastMax = -1;
    long long count = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] < minK || nums[i] > maxK) {
        leftBound = i, lastMin = -1, lastMax = -1;
        continue;
      }
      if (nums[i] == minK) lastMin = i;
      if (nums[i] == maxK) lastMax = i;
      count += max(0, min(lastMin, lastMax) - leftBound);
    }

    return count;
  }
};
