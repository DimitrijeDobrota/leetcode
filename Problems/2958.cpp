class Solution {
  public:
    int maxSubarrayLength(const vector<int> &nums, const int k) const {
        unordered_map<int, int> freq;
        const int n = size(nums);
        int res = 0, i = 0;

        for (int j = 0; j < n; j++) {
            freq[nums[j]]++;
            while (freq[nums[j]] > k)
                freq[nums[i++]]--;
            res = max(res, j - i + 1);
        }

        return max(res, n - i);
    }
};
