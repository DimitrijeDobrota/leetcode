class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> us;
        int n = nums.size(), i;
        for (i = 0; i <= k && i < n; i++) {
            if (us.count(nums[i])) return true;
            us.insert(nums[i]);
        }

        for (; i < n; i++) {
            us.erase(nums[i - k - 1]);
            if (us.count(nums[i])) return true;
            us.insert(nums[i]);
        }

        return false;
    }
};
