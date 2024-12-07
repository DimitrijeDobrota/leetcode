class Solution {
    static int dp[200][200][200];

    static int rec(const vector<int> &boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] > 0) return dp[l][r][k];

        int lOrg = l, kOrg = k;
        while (l + 1 <= r && boxes[l] == boxes[l + 1])
            l += 1, k += 1;

        int ans = (k + 1) * (k + 1) + rec(boxes, l + 1, r, 0);
        for (int m = l + 1; m <= r; ++m) {
            if (boxes[m] != boxes[l]) continue;
            ans = max(ans, rec(boxes, m, r, k + 1) + rec(boxes, l + 1, m - 1, 0));
        }
        return dp[lOrg][r][kOrg] = ans;
    }

  public:
    int removeBoxes(const vector<int> &boxes) const {
        memset(dp, 0x00, sizeof(dp));
        return rec(boxes, 0, size(boxes) - 1, 0);
    }
};

int Solution::dp[200][200][200];
