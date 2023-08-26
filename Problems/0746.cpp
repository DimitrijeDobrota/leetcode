// memorization approach
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> vec(cost.size() + 2);
        for (int i = 2; i <= cost.size(); i++)
            vec[i] = min(vec[i - 1] + cost[i - 1], vec[i - 2] + cost[i - 2]);
        return vec[cost.size()];
    }
};

// optimized, memorize only the previous two values
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int first = cost[0], second = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int crnt = cost[i] + min(first, second);
            first = second;
            second = crnt;
        }
        return min(first, second);
    }
};
