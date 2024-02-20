class Solution {
  public:
    int minimumDeletions(const vector<int> &nums) const {
        const int n = size(nums);
        int mini = nums[0], imini = 0;
        int maxi = nums[0], imaxi = 0;

        for (int i = 1; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                imini = i;
            }

            if (maxi < nums[i]) {
                maxi = nums[i];
                imaxi = i;
            }
        }

        return min(
            {imini + n - imaxi + 1, imaxi + n - imini + 1, max(imini, imaxi) + 1, n - min(imini, imaxi)});
    }
};
