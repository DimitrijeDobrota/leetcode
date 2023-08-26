class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;

        res.push_back({});
        for (int num : nums) {
            for (int i = res.size() - 1; i >= 0; i--) {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
};
