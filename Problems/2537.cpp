class Solution {
  public:
    long long countGood(const vector<int> &nums, int k) const {
        unordered_map<int, int> count;
        const int n = size(nums);
        long long res = 0;

        for (int i = 0, j = 0; j < n; j++) {
            k -= count[nums[j]]++;
            while (k <= 0)
                k += --count[nums[i++]];
            res += i;
        }

        return res;
    }
};
