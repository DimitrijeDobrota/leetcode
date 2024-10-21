class Solution {
    static int dp[1001][1001];

    static int rec(const string &s, const string &t, int check, int goal) {
        if (goal == size(t)) return 1;
        if (check == size(s)) return 0;
        if (dp[check][goal] != -1) return dp[check][goal];

        int res = rec(s, t, check + 1, goal);
        if (s[check] == t[goal]) res += rec(s, t, check + 1, goal + 1);
        return dp[check][goal] = res;
    }

  public:
    int numDistinct(const string &s, const string &t) const {
        memset(dp, 0xFF, sizeof(dp));
        return rec(s, t, 0, 0);
    }
};

int Solution::dp[1001][1001];
