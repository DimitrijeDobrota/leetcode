class Solution {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) const {
        int acc = 0;

        for (const int n : nums)
            acc += n;
        if (acc % k) return false;

        const int goal = acc / k;

        sort(rbegin(nums), rend(nums));
        if (nums[0] > goal) return false;

        const function<bool(uint16_t, int, int, int)> rec = [&](uint16_t visited, int left, int sum,
                                                                int start) {
            if (sum == goal) left--, sum = 0, start = 0;
            if (left == 1) return true;

            for (int i = start; i < size(nums); i++) {
                const uint16_t mask = 1 << i;
                if (visited & mask) continue;
                if (sum + nums[i] > goal) continue;

                if (rec(visited | mask, left, sum + nums[i], i + 1)) return true;
                if (sum == 0) return false;
            }

            return false;
        };

        return rec(1, k, nums[0], 1);
    }
};

class Solution {
  public:
    bool canPartitionKSubsets(vector<int> &nums, int k) const {
        static int acc[16];
        int sum = 0;

        for (const int n : nums)
            sum += n;
        if (sum % k) return false;

        const int goal = sum / k;

        sort(rbegin(nums), rend(nums));
        if (nums[0] > goal) return false;

        memset(acc, 0x00, sizeof(acc));
        acc[0] = nums[0];

        function<bool(int)> rec = [&](int crnt) {
            if (crnt == size(nums)) return true;

            for (int i = 0; i < k; i++) {
                if (acc[i] + nums[crnt] > goal) continue;

                acc[i] += nums[crnt];
                if (rec(crnt + 1)) return true;
                acc[i] -= nums[crnt];

                if (acc[i] == 0) return false;
            }

            return false;
        };

        return rec(1);
    }
};
