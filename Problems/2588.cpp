class Solution {
  public:
    long long beautifulSubarrays(const vector<int> &nums) const {
        static int count[1048577];
        long long res = 0;
        int crnt = 0;

        memset(count, 0x00, sizeof(count));
        count[0] = 1;
        for (const int n : nums) {
            crnt ^= n;
            res += count[crnt]++;
        }

        return res;
    }
};
