static const auto _ = [] {
    cin.tie(0);
    ios::sync_with_stdio(0);
    return 0;
}();
class Solution {
  public:
    int maxFrequency(vector<int> &nums, int k) const {
        static long long prefix[100001];
        const int n = nums.size();

        memset(prefix, 0x00, sizeof(prefix));
        for (int i = 0; i < n; i++)
            prefix[nums[i]]++;

        for (int i = 0, j = 0; i <= 100000; i++) {
            while (prefix[i] > 0) {
                nums[j++] = i, prefix[i]--;
            }
        }

        prefix[0] = 0;
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i - 1] + prefix[i - 1];

        int res = 0;
        for (int crnt = 0; crnt < n; crnt++) {
            int low = 0, high = crnt - 1;
            while (low <= high) {
                const int mid = low + (high - low) / 2;
                const long long left = crnt - mid;
                const long long sum = prefix[crnt] - prefix[mid];
                if (left * nums[crnt] - sum <= k)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            res = max(res, crnt - high);
        }

        return res;
    }
};
