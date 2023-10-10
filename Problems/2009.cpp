class Solution {
  public:
    int minOperations(vector<int> &nums) const {
        const int n = nums.size();
        sort(begin(nums), end(nums));
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int res = INT_MIN, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] < nums[i] + n)
                j++;
            res = max(res, j - i);
        }
        return n - res;
    }
};
