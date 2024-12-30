// Brute force
class Solution {
  public:
    int countPairs(const vector<int> &nums, int target) const {
        const int n = size(nums);
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                res += nums[i] + nums[j] < target;
            }
        }

        return res;
    }
};

// Two pointer
class Solution {
  public:
    int countPairs(vector<int> &nums, int target) const {
        int i = 0, j = size(nums) - 1;
        int res = 0;

        sort(begin(nums), end(nums));
        while (i < j) {
            if (nums[i] + nums[j] < target)
                res += j - i, i++;
            else
                j--;
        }

        return res;
    }
};
