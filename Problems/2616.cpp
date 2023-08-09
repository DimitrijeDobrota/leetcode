class Solution {
  int count(const vector<int> &nums, int treshold) {
    int cnt = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] <= treshold) cnt++, i++;
    }
    return cnt;
  }

public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums.front();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (count(nums, mid) >= p)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
};
