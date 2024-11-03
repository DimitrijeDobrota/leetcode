// programming solution
class Solution {
    static int seen[1001][1001];

    static bool rec(int x, int y, int target, int a = 0, int b = 0) {
        if (a + b == target) return true;
        if (seen[a][b]) return false;
        seen[a][b] = true;

        const int leftx = x - a;
        const int lefty = y - b;

        if (rec(x, y, target, x, b)) return true;
        if (rec(x, y, target, a, y)) return true;
        if (rec(x, y, target, 0, b)) return true;
        if (rec(x, y, target, a, 0)) return true;
        if (rec(x, y, target, a - min(a, lefty), b + min(a, lefty))) return true;
        if (rec(x, y, target, a + min(b, leftx), b - min(b, leftx))) return true;

        return false;
    }

  public:
    bool canMeasureWater(int x, int y, int target) const {
        memset(seen, 0x00, sizeof(seen));
        return rec(x, y, target);
    }
};

int Solution::seen[1001][1001];

// Math solution: Bézout's identity
class Solution {
  public:
    bool canMeasureWater(int x, int y, int target) const {
        if (x + y < target) return false;
        if (x == target || y == target || x + y == target) return true;
        return target % gcd(x, y) == 0;
    }
};
