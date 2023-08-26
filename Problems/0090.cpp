class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}, {nums[0]}};

        int prev = 1;
        for (int i = 1; i < nums.size(); i++) {
            int end = nums[i] == nums[i - 1] ? prev : 0;
            prev = res.size();
            for (int j = res.size() - 1; j >= end; j--) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }

        return res;
    }
};
