class Solution {
    static long long countLess(const vector<int> &nums, int target) {
        long long res = 0;

        for (int i = 0, j = size(nums) - 1; i < j; i++) {
            while (i < j && nums[i] + nums[j] > target)
                j--;
            res += j - i;
        }

        return res;
    }

  public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) const {
        sort(begin(nums), end(nums));
        return countLess(nums, upper) - countLess(nums, lower - 1);
    }
};
