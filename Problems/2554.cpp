class Solution {
  public:
    int maxCount(const vector<int> &banned, int n, int maxSum) const {
        unordered_set<int> us(begin(banned), end(banned));

        int res = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (us.count(i)) continue;
            sum += i;
            if (sum > maxSum) return res;
            res++;
        }

        return res;
    }
};
