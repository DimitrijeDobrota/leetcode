class Solution {
    static int prefix[1001], suffix[1001];
    static int n;

    int solve(const int firstLen, const int secondLen) const {
        static int left[1001], right[1001];

        left[firstLen - 1] = right[n - secondLen + 1] = 0;
        for (int i = firstLen; i <= n; i++)
            left[i] = max(left[i - 1], prefix[i] - prefix[i - firstLen]);
        for (int i = n - secondLen; i >= 0; i--)
            right[i] = max(right[i + 1], suffix[i] - suffix[i + secondLen]);

        int res = 0;
        for (int i = firstLen; i <= n - secondLen; i++)
            res = max(res, left[i] + right[i]);
        return res;
    }

  public:
    int maxSumTwoNoOverlap(const vector<int> &nums, int firstLen, int secondLen) const {
        n = nums.size();

        prefix[0] = 0, suffix[n] = 0;
        for (int i = 0, acc = 0; i < n; i++)
            prefix[i + 1] = acc += nums[i];
        for (int i = n - 1, acc = 0; i >= 0; i--)
            suffix[i] = acc += nums[i];

        return max(solve(firstLen, secondLen), solve(secondLen, firstLen));
    }
};

int Solution::prefix[1001];
int Solution::suffix[1001];
int Solution::n;
