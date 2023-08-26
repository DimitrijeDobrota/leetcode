class Solution {
  public:
    vector<vector<int>> findMatrix(const vector<int> &nums) {
        int count[201] = {0};
        vector<vector<int>> res;
        for (int n : nums) {
            if (count[n] >= res.size())
                res.push_back({n});
            else
                res[count[n]].push_back(n);
            count[n]++;
        }
        return res;
    }
};
