class Solution {
  public:
    int longestOnes(const vector<int> &nums, int k) {
        int maxi = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, i - left);
            if (!nums[i]) k--;
            while (k < 0)
                if (!nums[left++]) k++;
        }
        return max(maxi, (int)nums.size() - left);
    }
};
