class Solution {
  public:
    vector<int> createTargetArray(const vector<int> &nums, const vector<int> &index) const {
        vector<int> res;

        for (int i = 0; i < size(nums); i++) {
            res.insert(begin(res) + index[i], nums[i]);
        }

        return res;
    }
};
