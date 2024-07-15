class Solution {
  public:
    int minOperations(const vector<int> &nums) const {
        int res = 0;

        for (const int n : nums) {
            if ((n + res) % 2) continue;
            res++;
        }

        return res;
    }
};
