class Solution {
public:
  int reverse(int x) {
    if (x == INT_MIN || x == INT_MAX) return 0;

    bool neg = false;
    unsigned long res = 0;

    if (x < 0) {
      neg = true;
      x = -x;
    }

    do { res = res * 10 + x % 10; } while ((x /= 10) > 0);

    if (res > INT_MAX) return 0;
    return !neg ? res : -res;
  }
};
