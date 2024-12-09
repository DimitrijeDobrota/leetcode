class Solution {
  public:
    vector<bool> isArraySpecial(const vector<int> &nums, const vector<vector<int>> &queries) const {
        static int vec[100001];

        for (int i = 1; i < size(nums); i++) {
            vec[i] = vec[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);
        }

        vector<bool> res;
        for (const auto &query : queries) {
            res.push_back(vec[query[0]] == vec[query[1]]);
        }

        return res;
    }
};
