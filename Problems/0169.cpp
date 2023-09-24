// Naive Solution
class Solution {
  public:
    int majorityElement(const vector<int> &nums) {
        unordered_map<int, unsigned> um;
        for (int n : nums)
            um[n]++;
        for (auto [k, v] : um)
            if (v > (nums.size() / 2)) return k;
        return -1;
    }
};

// Boyer-Moore Algorithm: O(n) time, O(1) space
class Solution {
  public:
    int majorityElement(const vector<int> &nums) {
        int candid = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (!count) candid = nums[i];
            if (candid == nums[i])
                count++;
            else
                count--;
        }
        return candid;
    }
};
