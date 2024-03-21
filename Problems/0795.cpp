class Solution {
  public:
    int numSubarrayBoundedMax(const vector<int> &nums, int left, int right) const {
        int res = 0, good = -1, last = -1;

        for (int i = 0; i < size(nums); i++) {
            if (nums[i] < left)
                res += good - last;
            else if (nums[i] > right)
                good = last = i;
            else {
                res += i - last;
                good = i;
            }
        }

        return res;
    }
};
