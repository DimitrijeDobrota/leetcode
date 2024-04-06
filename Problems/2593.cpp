class Solution {
  public:
    long long findScore(const vector<int> &nums) const {
        static uint8_t marked[500002];
        static int indices[500002];

        const int n = size(nums);
        long long res = 0;

        memset(marked, 0x00, sizeof(marked));
        iota(begin(indices), begin(indices) + n, 0);
        sort(begin(indices), begin(indices) + n,
             [&nums](int a, int b) { return nums[a] != nums[b] ? nums[a] < nums[b] : a < b; });

        for (int i = 0; i < n; i++) {
            const int idx = indices[i];
            if (marked[idx + 1]) continue;
            marked[idx] = marked[idx + 1] = marked[idx + 2] = 1;
            res += nums[idx];
        }

        return res;
    }
};
