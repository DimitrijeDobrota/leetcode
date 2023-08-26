// Initial solution
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<int, int> crnt;
        crnt[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> next;
            for (auto &p : crnt) {
                next[p.first + nums[i]] += p.second;
                next[p.first - nums[i]] += p.second;
            }
            crnt = next;
        }
        return crnt[target];
    }
};

// Optimized using array;
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * total + 1);
        dp[total] = 1;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> next(2 * total + 1);
            for (int j = 0; j < dp.size(); j++) {
                if (!dp[j]) continue;
                next[j + nums[i]] += dp[j];
                next[j - nums[i]] += dp[j];
            }
            dp = next;
        }
        return abs(target) > total ? 0 : dp[target + total];
    }
};
