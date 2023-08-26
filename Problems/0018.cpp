class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long goal = (long long)target - nums[i] - nums[j];
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long crnt = nums[k] + nums[l];
                    if (crnt > goal)
                        l--;
                    else if (crnt < goal)
                        k++;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    ++j;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                ++i;
        }
        return res;
    }
};
