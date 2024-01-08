class Solution {
  public:
    int getMaximumConsecutive(vector<int> &coins) const {
        sort(begin(coins), end(coins));
        int res = 1;
        for (const int c : coins) {
            if (c > res) break;
            res += c;
        }
        return res;
    }
};
