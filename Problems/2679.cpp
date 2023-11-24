class Solution {
  public:
    int matrixSum(const vector<vector<int>> &nums) const {
        static int maxi[501];
        memset(maxi, 0x00, sizeof(maxi));

        const int m = nums[0].size();
        for (auto row : nums) {
            sort(row.begin(), row.end());
            for (int i = 0; i < m; i++)
                maxi[i] = max(maxi[i], row[i]);
        }

        return accumulate(begin(maxi), begin(maxi) + m, 0);
    }
};
