class Solution {
  public:
    long long largestPerimeter(vector<int> &nums) const {
        sort(begin(nums), end(nums));

        long long res = -1, crnt = 0;
        for (int i = 0; i < size(nums); i++) {
            crnt += nums[i];
            if (crnt > nums[i] * 2) res = crnt;
        }

        return res;
    }
};
