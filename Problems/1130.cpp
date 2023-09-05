class Solution {
  public:
    int mctFromLeafValues(vector<int> &arr) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int n : arr) {
            while (stack.back() <= n) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), n);
            }
            stack.push_back(n);
        }

        for (int i = 2; i < stack.size(); i++)
            res += stack[i] * stack[i - 1];

        return res;
    }
};
