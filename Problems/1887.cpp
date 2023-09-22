class Solution {
  public:
    int reductionOperations(const vector<int> &nums) {
        static int count[50001];
        memset(count, 0x00, sizeof(count));

        int res = 0, cnt = 0;
        for (const int n : nums)
            count[n]++;
        for (int i = 50000; i >= 0; i--) {
            if (count[i]) res += cnt += count[i];
        }
        return res - cnt;
    }
};
