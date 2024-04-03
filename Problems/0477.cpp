class Solution {
  public:
    int totalHammingDistance(const vector<int> &nums) const {
        const int n = size(nums);
        int res = 0;

        for (unsigned mask = 1; mask <= 1 << 30; mask <<= 1) {
            int count =
                accumulate(begin(nums), end(nums), 0, [&mask](int a, int b) { return a + !!(b & mask); });
            res += count * (n - count);
        }

        return res;
    }
};
