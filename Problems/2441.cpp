class Solution {
  public:
    int findMaxK(const vector<int> &nums) const {
        static uint8_t us[2001];
        int res = -1;

        memset(us, 0x00, sizeof(us));
        for (const int n : nums) {
            if (us[-n + 1000]) res = max(res, abs(n));
            us[n + 1000] = 1;
        }

        return res;
    }
};
