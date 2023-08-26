class Solution {
  public:
    vector<bool> checkArithmeticSubarrays(const vector<int> &nums, const vector<int> &l,
                                          const vector<int> &r) {
        int n = nums.size(), m = l.size();
        vector<bool> res(m, true);
        for (int q = 0; q < m; q++) {
            if (r[q] - l[q] < 2) continue;
            vector<int> range(nums.begin() + l[q], nums.begin() + r[q] + 1);
            sort(range.begin(), range.end());
            const int diff = range[1] - range[0];
            for (int i = 2; i < range.size(); i++) {
                if (range[i] - range[i - 1] != diff) {
                    res[q] = false;
                    break;
                }
            }
        }
        return res;
    }
};
