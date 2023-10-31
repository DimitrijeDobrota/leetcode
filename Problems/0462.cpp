class Solution {
  public:
    int minMoves2(vector<int> &nums) const {
        int res = 0, i = 0, j = nums.size() - 1;
        sort(begin(nums), end(nums));
        while (i < j)
            res += nums[j--] - nums[i++];
        return res;
    }
};

// Optimized solution
class Solution {
  public:
    int minMoves2(vector<int> &nums) const {
        const int n = nums.size(), mid = n / 2;
        nth_element(begin(nums), begin(nums) + mid, end(nums));
        const int median = nums[mid];
        int res = 0;
        for (int i = 0; i < n; i++)
            res += abs(nums[i] - median);
        return res;
    }
};
