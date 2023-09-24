class Solution {
  public:
    int minimumIndex(const vector<int> &nums) {
        int candid = nums[0], count = 0;
        for (const int n : nums) {
            if (!count) candid = n;
            count += candid == n ? 1 : -1;
        }

        int ccount = 0;
        for (const int n : nums)
            if (n == candid) ccount++;

        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candid) count++;
            if ((count * 2 > i + 1) && (ccount - count) * 2 > nums.size() - i - 1) return i;
        }

        return -1;
    }
};
