class Solution {
  public:
    int specialArray(const vector<int> &nums) const {
        static int count[102];
        const int n = size(nums);

        memset(count, 0x00, sizeof(count));
        for (const int m : nums)
            count[min(n, m)]++;
        for (int i = size(nums); i >= 0; i--) {
            count[i] += count[i + 1];
            if (count[i] == i) return i;
        }

        return -1;
    }
};
