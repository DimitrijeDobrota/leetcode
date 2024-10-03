class Solution {
  public:
    int minSubarray(const vector<int> &nums, int p) const {
        const int n = size(nums);

        int target = 0;
        for (const int n : nums)
            target = (target + n) % p; // avoid overflow
        if (target == 0) return 0;

        unordered_map<int, int> um;
        int res = n, crnt = 0;
        um[0] = -1;

        for (int i = 0; i < n; i++) {
            crnt = (crnt + nums[i]) % p;

            const int goal = (crnt - target + p) % p;
            if (um.count(goal)) res = min(res, i - um[goal]);

            um[crnt] = i;
        }

        return res == n ? -1 : res;
    }
};
