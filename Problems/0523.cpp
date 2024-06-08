class Solution {
  public:
    bool checkSubarraySum(const vector<int> &nums, int k) const {
        unordered_set<int> seen;

        for (int i = 0, sum = 0, pre = 0; i < size(nums); i++) {
            sum += nums[i];
            if (seen.count(sum % k)) return true;
            seen.insert(pre);
            pre = sum % k;
        }

        return false;
    }
};
