class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
            if (um.find(target - nums[i]) != um.end())
                return {um[target - nums[i]], i};
            else
                um.insert(make_pair(nums[i], i));
        return {};
    }
};
