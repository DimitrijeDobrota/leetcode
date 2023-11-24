class Solution {
  public:
    int minIncrements(int n, vector<int> &cost) const {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; i--) {
            const int next = i << 1;
            res += abs(cost[next + 1] - cost[next + 2]);
            cost[i] += max(cost[next + 1], cost[next + 2]);
        }
        return res;
    }
};
