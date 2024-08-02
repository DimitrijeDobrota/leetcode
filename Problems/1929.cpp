class Solution {
  public:
    vector<int> getConcatenation(vector<int> &nums) const {
        const int n = size(nums);

        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        return nums;
    }
};
