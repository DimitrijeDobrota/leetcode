class Solution {
  public:
    int longestNiceSubarray(const vector<int> &nums) const {
        int res = 0, used = 0, j = 0;

        for (int i = 0; i < size(nums); i++) {
            while (used & nums[i])
                used ^= nums[j++];
            used |= nums[i];
            res = max(res, i - j);
        }

        return res + 1;
    }
};
