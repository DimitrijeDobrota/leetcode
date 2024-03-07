class Solution {
  public:
    int countMatchingSubarrays(const vector<int> &nums, const vector<int> &pattern) const {
        const int n = size(nums), m = size(pattern);
        int res = 0;

        for (int i = 1; i <= n - m; i++) {
            for (int j = 0; j < m; j++) {
                if (pattern[j] == -1 && nums[i + j] >= nums[i + j - 1]) goto next;
                if (pattern[j] == 0 && nums[i + j] != nums[i + j - 1]) goto next;
                if (pattern[j] == 1 && nums[i + j] <= nums[i + j - 1]) goto next;
            }
            res++;
        next:;
        }

        return res;
    }
};
