class Solution {
  public:
    int longestSubarray(const vector<int> &nums) const {
        const int maxi = *max_element(begin(nums), end(nums));

        int res = 0, cnt = 0;
        for (const int n : nums) {
            if (n == maxi)
                cnt++;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }

        return max(res, cnt);
    }
};
