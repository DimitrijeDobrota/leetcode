class Solution {
    vector<vector<int>> res;
    vector<int> crnt;

    void rec(vector<int> &candidates, int target, int sum, int start = 0) {
        if (sum == target)
            res.push_back(crnt);
        else if (sum < target) {
            for (int i = start; i < candidates.size(); i++) {
                crnt.push_back(candidates[i]);
                rec(candidates, target, sum + candidates[i], i);
                crnt.pop_back();
            }
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, 0);
        return res;
    }
};
