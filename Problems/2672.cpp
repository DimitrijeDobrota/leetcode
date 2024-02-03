class Solution {
  public:
    vector<int> colorTheArray(const int n, const vector<vector<int>> &queries) const {
        static int nums[100002];
        memset(nums, 0x00, sizeof(nums));

        const int m = size(queries);
        vector<int> res(m);

        int crnt = 0;
        for (int i = 0; i < m; i++) {
            const int idx = queries[i][0] + 1;
            const int color = queries[i][1];
            if (nums[idx] != color) {
                if (nums[idx]) {
                    if (nums[idx] == nums[idx - 1]) crnt--;
                    if (nums[idx] == nums[idx + 1]) crnt--;
                }
                nums[idx] = color;
                if (nums[idx] == nums[idx - 1]) crnt++;
                if (nums[idx] == nums[idx + 1]) crnt++;
            }
            res[i] = crnt;
        }

        return res;
    }
};
