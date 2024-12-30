// Brute force
class Solution {
  public:
    int differenceOfSums(int n, int m) const {
        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m)
                res += i;
            else
                res -= i;
        }

        return res;
    }
};

// Math
class Solution {
  public:
    int differenceOfSums(int n, int m) const { return n * (n + 1) / 2 - m * (n / m) * (n / m + 1); }
};
