class Solution {
  public:
    vector<int> resultsArray(const vector<int> &nums, int k) const {
        const int n = size(nums);
        vector<int> res(n - k + 1, -1);

        for (int i = 0; i <= n - k; i++) {
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j - 1] + 1 == nums[j]) continue;
                i = j - 1;
                goto next;
            }
            res[i] = nums[i + k - 1];
        next:;
        }

        return res;
    }
};
