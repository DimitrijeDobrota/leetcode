class Solution {
  public:
    int minKBitFlips(vector<int> &nums, int k) const {
        const int n = size(nums);
        int res = 0, flips = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == flips % 2) {
                if (i > n - k) return -1;
                nums[i] -= 2, res++, flips++;
            }

            const int prev = i - k + 1;
            if (i >= k - 1 && nums[prev] < 0) nums[prev] += 2, flips--;
        }

        return res;
    }
};
