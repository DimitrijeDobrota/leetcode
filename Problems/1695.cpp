class Solution {
  public:
    int maximumUniqueSubarray(const vector<int> &nums) const {
        static bool seen[10001];
        memset(seen, 0x00, sizeof(seen));
        int res = 0, sum = 0, i = 0;
        for (int j = 0; j < nums.size(); j++) {
            while (seen[nums[j]]) {
                seen[nums[i]] = 0;
                sum -= nums[i++];
            }
            seen[nums[j]] = 1;
            sum += nums[j];
            res = max(res, sum);
        }
        return res;
    }
};
