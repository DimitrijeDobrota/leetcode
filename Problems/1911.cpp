
// Standard dp
class Solution {
    static long long dp[2][100001];
    long long rec(const vector<int> &nums, const int crnt, const bool odd) {
        if (crnt >= size(nums)) return 0;
        if (dp[odd][crnt] != -1) return dp[odd][crnt];
        long long res =
            max(rec(nums, crnt + 1, odd), (odd ? -1 : 1) * nums[crnt] + rec(nums, crnt + 1, !odd));
        return dp[odd][crnt] = res;
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    long long maxAlternatingSum(const vector<int> &nums) { return rec(nums, 0, 0); }
};

long long Solution::dp[2][100001];

// Optimized 1
class Solution {
  public:
    long long maxAlternatingSum(const vector<int> &nums) const {
        long long odd = 0, even = 0;
        for (const int n : nums) {
            even = max(even, odd + n), odd = even - n;
        }
        return even;
    }
};

// Optimized 2
class Solution {
  public:
    long long maxAlternatingSum(const vector<int> &nums) const {
        long long res = nums[0];
        for (int i = 1; i < size(nums); i++) {
            res += max(nums[i] - nums[i - 1], 0);
        }
        return res;
    }
};
