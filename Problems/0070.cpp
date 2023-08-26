// memorization approach
class Solution {
  public:
    int climbStairs(int n) {
        vector<int> vec(46);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= n; i++)
            vec[i] = vec[i - 1] + vec[i - 2];

        return vec[n];
    }
}

// optimized, memorize only the previous two values
class Solution {
  public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        for (int i = 2; i <= n; i++) {
            int cnt = first + second;
            first = second;
            second = cnt;
        }

        return second;
    }
};
