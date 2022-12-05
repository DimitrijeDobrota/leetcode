class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> vec(cost.size() + 2);
    for (int i = 2; i <= cost.size(); i++)
      vec[i] = min(vec[i - 1] + cost[i - 1], vec[i - 2] + cost[i - 2]);
    return vec[cost.size()];
  }

  int minCostClimbingStairs(vector<int> &cost) {
    int first = cost[0], second = cost[1];
    if (cost.size() <= 2) return min(first, second);
    for (int i = 2; i < cost.size(); i++) {
      int cur = cost[i] + min(first, second);
      first = second;
      second = cur;
    }
    return min(first, second);
  }
};
