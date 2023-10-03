class Solution {
  public:
    int numIdenticalPairs(const vector<int> &nums) {
        int count[101] = {0}, res = 0;
        for (const int n : nums)
            res += count[n]++;
        return res;
    }
};
