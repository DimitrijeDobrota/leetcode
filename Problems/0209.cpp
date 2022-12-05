class Solution {
  int inf = 100001;

public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int i = 0, j = 0;
    int mini = inf;
    int sum = nums[0];
    int cnt = 1;
    while (true) {
      if (sum >= target) {
        do {
          mini = min(mini, cnt);
          sum -= nums[i++];
          cnt--;
        } while (i < j && sum >= target);
      } else {
        if (++j >= nums.size()) break;
        sum += nums[j];
        cnt++;
      }
    }
    if (mini == inf) return 0;
    return mini;
  }
};
