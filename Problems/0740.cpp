class Solution {
  public:
    int deleteAndEarn(vector<int> &nums) {
        int n = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> count(n);
        for (int n : nums)
            count[n] += n;

        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < n; i++) {
            int tmp = prev1;
            prev1 = max(prev2 + count[i], prev1);
            prev2 = tmp;
        }

        return prev1;
    }
};
