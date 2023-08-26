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
