class Solution {
  public:
    bool checkPossibility(const vector<int> &nums) const {
        const int n = size(nums);
        int cnt1 = 0, cnt2 = 0;

        for (int i = 1, prev = nums[0]; i < n && cnt1 <= 1; i++) {
            if (nums[i] < prev)
                cnt1++;
            else
                prev = nums[i];
        }

        if (cnt1 <= 1) return true;

        for (int i = n - 2, prev = nums[n - 1]; i >= 0 && cnt2 <= 1; i--) {
            if (nums[i] > prev)
                cnt2++;
            else
                prev = nums[i];
        }

        return cnt2 <= 1;
    }
};
