class Solution {
  public:
    long long countAlternatingSubarrays(const vector<int> &nums) const {
        long long res = 1;

        for (int i = 1, cnt = 1; i < size(nums); i++) {
            cnt = nums[i] == nums[i - 1] ? 1 : cnt + 1;
            res += cnt;
        }

        return res;
    }
};
