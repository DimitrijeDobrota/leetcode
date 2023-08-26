// memorization approach
class Solution {
  public:
    int tribonacci(int n) {
        vector<int> f(38);
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        for (int i = 3; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2] + f[i - 3];
        return f[n];
    }
};

// optimized, memorize only the previous three values
class Solution {
  public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};
