class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (!nums.size()) return 0;

    unordered_set<int> us(nums.begin(), nums.end());
    int res = 0;

    for (int num : us) {
      if (!us.count(num - 1)) {
        int crnt = num;
        while (us.count(crnt + 1)) crnt += 1;
        res = max(longestStreak, crnt - num);
      }
    }

    return res + 1;
  }
};
