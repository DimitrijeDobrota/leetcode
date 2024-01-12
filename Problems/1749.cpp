class Solution {
  public:
    int maxAbsoluteSum(const vector<int> &nums) const {
        int mini = 0, maxi = 0, res = 0;
        for (const int n : nums) {
            maxi = max(0, maxi + n);
            mini = min(0, mini + n);
            res = max({res, maxi, -mini});
        }
        return res;
    }
};

class Solution {
  public:
    int maxAbsoluteSum(const vector<int> &nums) const {
        int mini = 0, maxi = 0, sum = 0;
        for (const int n : nums) {
            sum += n;
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        return maxi - mini;
    }
};
