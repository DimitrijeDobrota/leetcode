class Solution {
  public:
    vector<int> maxSumOfThreeSubarrays(const vector<int> &nums, int k) const {
        const int n = nums.size();

        static int sum[4][20003], index[4][20003];
        static int prefix[20003];

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        memset(sum, 0x00, sizeof(sum));
        memset(index, 0x00, sizeof(index));
        for (int cnt = 1; cnt <= 3; cnt++) {
            for (int end = k * cnt; end <= n; end++) {
                const int currentSum = prefix[end] - prefix[end - k] + sum[cnt - 1][end - k];

                if (currentSum > sum[cnt][end - 1]) {
                    sum[cnt][end] = currentSum;
                    index[cnt][end] = end - k;
                } else {
                    sum[cnt][end] = sum[cnt][end - 1];
                    index[cnt][end] = index[cnt][end - 1];
                }
            }
        }

        int end = n;
        vector<int> result(3, 0);
        for (int idx = 3; idx >= 1; idx--) {
            result[idx - 1] = index[idx][end];
            end = result[idx - 1];
        }

        return result;
    }
};
