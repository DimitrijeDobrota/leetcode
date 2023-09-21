class Solution {
    int atMost(const vector<int> &nums, int k) {
        int res = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) k--;
            while (k < 0)
                if (nums[j++] % 2) k++;
            res += i - j + 1;
        }
        return res;
    }

  public:
    int numberOfSubarrays(const vector<int> &nums, int k) { return atMost(nums, k) - atMost(nums, k - 1); }
};
