class Solution {
  public:
    bool circularArrayLoop(vector<int> &nums) const {
        const int n = size(nums);
        static int seen[5001];

        const auto next = [&](int k) {
            const int res = (k + nums[k] % n + n) % n;
            seen[res] = true;
            return res;
        };

        memset(seen, 0x00, sizeof(seen));
        for (auto &num : nums)
            num %= n;

        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            int t = i, h = i;

            do {
                t = next(t);
                h = next(next(h));
            } while (t != h);

            const bool dir = nums[t] > 0;
            do {
                t = next(t);
                if ((nums[t] > 0) != dir) goto next;
            } while (t != h);

            if ((t + nums[t] + n) % n != t) return true;
        next:;
        }

        return false;
    }
};
