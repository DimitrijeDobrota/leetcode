// memorization approach
class Solution {
public:
  int fib(int n) {
    vector<int> f(31);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    return f[n];
  }
};

// optimized, memorize only the previous two values
class Solution {
public:
  int fib(int n) {
    if (n == 0) return 0;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
      int tmp = a + b;
      a = b;
      b = tmp;
    }
    return b;
  }
};
