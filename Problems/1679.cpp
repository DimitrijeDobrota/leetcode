class Solution {
  public:
    int maxOperations(vector<int> &nums, const int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, res = 0;
        while (i < j) {
            const int sum = nums[i] + nums[j];
            if (sum == k)
                i++, j--, res++;
            else if (sum < k)
                i++;
            else
                j--;
        }
        return res;
    }
};
