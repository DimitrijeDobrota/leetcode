class Solution {
  public:
    int minOperations(const vector<int> &nums) const {
        unordered_map<int, int> count;
        for (const int n : nums)
            count[n]++;

        int res = 0;
        for (const auto [_, cnt] : count) {
            if (cnt == 1) return -1;
            res += ceil((double)cnt / 3);
        }
        return res;
    }
};
