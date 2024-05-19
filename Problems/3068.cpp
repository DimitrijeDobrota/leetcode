class Solution {
  public:
    long long maximumValueSum(const vector<int> &nums, int k, const vector<vector<int>> &edges) const {
        int count = 0, mini = INT_MAX, maxi = INT_MIN;
        long long total = 0;

        for (const int val : nums) {
            const int after = val ^ k;
            const int change = after - val;
            total += val;

            if (change > 0) {
                mini = min(mini, change);
                total += change;
                count++;
            } else {
                maxi = max(maxi, change);
            }
        }

        if (count % 2 == 0) return total;
        return max(total - mini, total + maxi);
    }
};
