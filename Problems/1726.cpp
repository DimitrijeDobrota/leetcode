class Solution {
  public:
    int tupleSameProduct(const vector<int> &nums) const {
        unordered_map<int, int> um;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                const int prod = nums[i] * nums[j];
                res += 8 * um[prod]++;
            }
        }
        return res;
    }
};
