class Solution {
  public:
    vector<int> maxScoreIndices(const vector<int> &nums) {
        int score = accumulate(begin(nums), end(nums), 0);
        vector<int> res = {0};
        for (int i = 0, maxi = score; i < nums.size(); i++) {
            score += (nums[i] == 0) ? 1 : -1;

            if (score < maxi) continue;
            if (score > maxi) {
                res.clear();
                maxi = score;
            }
            res.push_back(i + 1);
        }

        return res;
    }
};
