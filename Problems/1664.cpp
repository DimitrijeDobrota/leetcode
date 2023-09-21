class Solution {
  public:
    int waysToMakeFair(const vector<int> &nums) {
        const int n = nums.size();
        int sodd = 0, seven = 0;
        for (int i = n - 1; i >= 0; i--)
            (i % 2 ? sodd : seven) += nums[i];

        int res = 0;
        for (int i = 0, odd = 0, even = 0; i < n; i++) {
            const int codd = odd + seven - even + (i % 2 ? nums[i] : 0);
            const int ceven = even + sodd - odd + (i % 2 ? 0 : nums[i]);
            if (codd == ceven) res++;
            (i % 2 ? odd : even) += nums[i];
        }

        return res;
    }
};
