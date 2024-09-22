class Solution {
    static int count(int n, long p1, long p2) {
        int steps = 0;
        while (p1 <= n) {

            steps += min((long)(n + 1), p2) - p1;
            p1 *= 10, p2 *= 10;
        }

        return steps;
    }

  public:
    int findKthNumber(int n, int k) const {
        int crnt = 1;
        k--;

        while (k > 0) {
            int step = count(n, crnt, crnt + 1);
            if (step <= k) {
                crnt++;
                k -= step;
            } else {
                crnt *= 10;
                k--;
            }
        }

        return crnt;
    }
};
