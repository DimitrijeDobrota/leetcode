class Solution {
  public:
    int longestSubsequence(const vector<int> &arr, int diff) {
        unordered_map<int, int> dp;

        int res = 1;
        for (int n : arr) {
            int before = dp.count(n - diff) ? dp[n - diff] : 0;
            res = max(res, dp[n] = before + 1);
        }

        return res;
    }
};
