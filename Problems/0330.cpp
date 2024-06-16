class Solution {
  public:
    int minPatches(const vector<int> &nums, const int n) const {
        long long sum = 0;
        int res = 0, i = 0;

        while (sum < n) {
            if (i < size(nums) && nums[i] <= sum + 1)
                sum += nums[i++];
            else
                sum += sum + 1, res++;
        }

        return res;
    }
};
