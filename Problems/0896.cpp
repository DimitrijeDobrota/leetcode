class Solution {
  public:
    bool isMonotonic(const vector<int> &nums) {
        bool inc = false, dec = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) dec = true;
            if (nums[i] < nums[i - 1]) inc = true;
            if (dec && inc) break;
        }
        return !(dec & inc);
    }
};
