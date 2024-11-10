class Solution {
    inline static int update(int count[32], int num, int value) {
        int crnt = 0;

        for (int k = 0; k < 32; k++) {
            const auto bit = 1 << k;
            if (num & bit) count[k] += value;
            if (count[k]) crnt |= bit;
        }

        return crnt;
    }

  public:
    int minimumSubarrayLength(const vector<int> &nums, int k) const {
        static int count[32];
        unsigned res = -1;

        memset(count, 0x00, sizeof(count));
        for (int i = 0, j = 0; j < size(nums); j++) {
            int crnt = update(count, nums[j], 1);

            for (; i <= j && crnt >= k; i++) {
                res = min(res, (unsigned)(j - i + 1));
                crnt = update(count, nums[i], -1);
            }
        }

        return res;
    }
};
