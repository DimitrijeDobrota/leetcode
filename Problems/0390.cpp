class Solution {
  public:
    int lastRemaining(int n) const {
        int head = 1;

        for (int step = 1, dir = 1; n > 1; step *= 2, n /= 2, dir = !dir) {
            head += dir || n % 2 ? step : 0;
        }

        return head;
    }
};
